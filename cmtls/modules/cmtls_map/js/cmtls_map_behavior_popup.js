
/**
 * OpenLayers Popup Behavior
 */
Drupal.behaviors.cmtls_map_behavior_popup = function(context)
{
	var data = $(context).data('openlayers');
	
	if (data && data.map.behaviors['cmtls_map_behavior_popup'])
	{
		var map = data.openlayers;
		var options = data.map.behaviors['cmtls_map_behavior_popup'];
		var layers = [];
		
		// For backwards compatiability, if layers is not
		// defined, then include all vector layers
		if (typeof options.layers == 'undefined' || options.layers.length == 0)
		{
			layers = map.getLayersByClass('OpenLayers.Layer.Vector');
		}
		else
		{
			for (var i in options.layers)
			{
				var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
				if (typeof selectedLayer[0] != 'undefined')
				{
					layers.push(selectedLayer[0]);
				}
			}
		}
		
		popupControl = new OpenLayers.Control.SelectFeature(layers,
		{
			onSelect: function(feature)
			{
				var map = feature.layer.map;
				
				// remove all other popups
				var popups = map.popups;
				var popups_length = popups.length;
				
				for(var i = 0; i < popups_length; i++)
				{
					map.removePopup(popups[i]);
				}
				
				var html = '';
				
				if(feature.cluster)
				{
					if(feature.cluster.length > 11)
					{
						map.panTo(feature.geometry.getBounds().getCenterLonLat());
						map.zoomIn();
						return;
					}
					
					for(var i = 0; i < feature.cluster.length; i++) if(feature.cluster[i].data.content)
					{
						html += feature.cluster[i].data.content;
					}
				}
				else if(feature.data.content)
				{
					html = feature.data.content;
				}
				
				if(html)
				{
					html = '<div class="cmtls-map-popup-contents" id="cmtls-map-popup-contents-' + feature.id.replace(/\./g, '-') + '"><a href="javascript:void(0);" onclick="closePopup(this);" class="cmtls-map-popup-close">&nbsp;</a>' + html + '</div>';
					
					if(feature.cluster)
					{
						html +=  '<div class="cmtls-map-popup-pager" id="cmtls-map-popup-pager-' + feature.id.replace(/\./g, '-') + '"><a href="javascript:void(0);" class="cmtls-map-popup-pager-previous" onclick="pagePopupContent(\'prev\', this);">&laquo;</a> <span class="cmtls-map-popup-pager-current"></span> of ' + feature.cluster.length + ' <a href="javascript:void(0);" onclick="pagePopupContent(\'next\', this);" class="cmtls-map-popup-pager-next">&raquo;</a></div>';
					}
					
					//var popup = new OpenLayers.Popup(feature.data.id, feature.geometry.getBounds().getCenterLonLat(), new OpenLayers.Size(300, 200), html, false);
					var popup = new OpenLayers.Popup.FramedCloud(feature.data.id, feature.geometry.getBounds().getCenterLonLat(), null, html, null, false);
					// Assign popup to feature and map.
					popup.panMapIfOutOfView = true;
					popup.imageSrc = Drupal.settings.basePath + 'sites/all/modules/cmtls/modules/cmtls_map/img/cloud-popup-relative.png';
					popup.isAlphaImage = true;
					
					popup.size = new OpenLayers.Size(300, 200);
					popup.minSize = new OpenLayers.Size(300, 200);
					popup.maxSize = new OpenLayers.Size(300, 200);
					
					popup.positionBlocks =
					{
					    "tl": {
					        'offset': new OpenLayers.Pixel(150, -7),
					        'padding': new OpenLayers.Bounds(7, 30, 7, 7),
					        'blocks':
					        [
						        {//ylemine ja vasak
						            size: new OpenLayers.Size('auto', 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 22, null), 
						            position: new OpenLayers.Pixel(0, 0)
						        },
								{//parem
						            size: new OpenLayers.Size(22, 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 0, null), 
						            position: new OpenLayers.Pixel(-638, 0)
						        },
								{//alus 
						            size: new OpenLayers.Size('auto', 23),
						            anchor: new OpenLayers.Bounds(null, 20, 22, null), 
						            position: new OpenLayers.Pixel(0, -631)
						        },
								{// parem all nurk
						            size: new OpenLayers.Size(22, 22),
						            anchor: new OpenLayers.Bounds(null, 20, 0, null), 
						            position: new OpenLayers.Pixel(-638, -632)
						        },
						        {
						            size: new OpenLayers.Size(32, 33), // kasti suurus
						            anchor: new OpenLayers.Bounds(134, 0, null, null),
						            position: new OpenLayers.Pixel(0, -658) // graafika offset kasti sees
						        }
							]					        
					    },
					    "tr": {
					        'offset': new OpenLayers.Pixel(-150, -7),
					        'padding': new OpenLayers.Bounds(7, 30, 7, 7),
					        'blocks':
					        [
						        {//ylemine ja vasak
						            size: new OpenLayers.Size('auto', 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 22, null), 
						            position: new OpenLayers.Pixel(0, 0)
						        },
								{//parem
						            size: new OpenLayers.Size(22, 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 0, null), 
						            position: new OpenLayers.Pixel(-638, 0)
						        },
								{//alus 
						            size: new OpenLayers.Size('auto', 23),
						            anchor: new OpenLayers.Bounds(null, 20, 22, null), 
						            position: new OpenLayers.Pixel(0, -631)
						        },
								{// parem all nurk
						            size: new OpenLayers.Size(22, 22),
						            anchor: new OpenLayers.Bounds(null, 20, 0, null), 
						            position: new OpenLayers.Pixel(-638, -632)
						        },
						        {
						            size: new OpenLayers.Size(32, 33), // kasti suurus
						            anchor: new OpenLayers.Bounds(134, 0, null, null),
						            position: new OpenLayers.Pixel(0, -658) // graafika offset kasti sees
						        }
							]					        
					    },
					    "bl": {
					        'offset': new OpenLayers.Pixel(150, -207),
					        'padding': new OpenLayers.Bounds(7, 30, 7, 7),
					        'blocks':
					        [
						        {//ylemine ja vasak
						            size: new OpenLayers.Size('auto', 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 22, null), 
						            position: new OpenLayers.Pixel(0, 0)
						        },
								{//parem
						            size: new OpenLayers.Size(22, 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 0, null), 
						            position: new OpenLayers.Pixel(-638, 0)
						        },
								{//alus 
						            size: new OpenLayers.Size('auto', 23),
						            anchor: new OpenLayers.Bounds(null, 20, 22, null), 
						            position: new OpenLayers.Pixel(0, -631)
						        },
								{// parem all nurk
						            size: new OpenLayers.Size(22, 22),
						            anchor: new OpenLayers.Bounds(null, 20, 0, null), 
						            position: new OpenLayers.Pixel(-638, -632)
						        },
						        {
						            size: new OpenLayers.Size(32, 33), // kasti suurus
						            anchor: new OpenLayers.Bounds(134, 0, null, null),
						            position: new OpenLayers.Pixel(0, -658) // graafika offset kasti sees
						        }
							]					        
					    },
					    "br": {
					        'offset': new OpenLayers.Pixel(-150, -207),
					        'padding': new OpenLayers.Bounds(7, 30, 7, 7),
					        'blocks':
					        [
						        {//ylemine ja vasak
						            size: new OpenLayers.Size('auto', 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 22, null), 
						            position: new OpenLayers.Pixel(0, 0)
						        },
								{//parem
						            size: new OpenLayers.Size(22, 'auto'),
						            anchor: new OpenLayers.Bounds(null, 42, 0, null), 
						            position: new OpenLayers.Pixel(-638, 0)
						        },
								{//alus 
						            size: new OpenLayers.Size('auto', 23),
						            anchor: new OpenLayers.Bounds(null, 20, 22, null), 
						            position: new OpenLayers.Pixel(0, -631)
						        },
								{// parem all nurk
						            size: new OpenLayers.Size(22, 22),
						            anchor: new OpenLayers.Bounds(null, 20, 0, null), 
						            position: new OpenLayers.Pixel(-638, -632)
						        },
						        {
						            size: new OpenLayers.Size(32, 33), // kasti suurus
						            anchor: new OpenLayers.Bounds(134, 0, null, null),
						            position: new OpenLayers.Pixel(0, -658) // graafika offset kasti sees
						        }
					        ]					        
					    }
					};
					
					feature.popup = popup;
					map.addPopup(popup);
					
					
					$('.cmtls-map-popup-content:first').removeClass('hidden');
					if(feature.cluster)
					{
						$('.cmtls-map-popup-pager-current').text('1');
					}
				}
				else
				{
					return;
				}
			},
			onUnselect: function (feature)
			{
				if(feature.popup)
				{
					feature.layer.map.removePopup(feature.popup);
					feature.popup.destroy();
					feature.popup = null;
				}
			}
		});
	
		popupControl.id = 'cmtls_map_pop_control';
		map.addControl(popupControl);
		popupControl.activate();

		featureHover = new OpenLayers.Control.SelectFeature(layers, {});
	
		featureHover.id = 'cmtls_map_feature_hover_control';
		map.addControl(featureHover);
	}
}
