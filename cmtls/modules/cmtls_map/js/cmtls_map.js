
Drupal.behaviors.cmtls_map = function(context)
{
	if(context == window.document)
	{
		mapResize();
		// resize the map when the window size changes
		$(window).resize(mapResize);
		
		$('.cmtls-map-popup').live('mouseover', function ()
		{
			var id = this.id.replace('cmtls-map-feature-', '');
			
			var data = $('#openlayers-map-auto-id-0').data('openlayers');
			
			if (data && data.map.behaviors['cmtls_map_behavior_popup'])
			{
				var map = data.openlayers;
				var hoverControl = null
				var layer = map.getLayersByName('cmtls_features')[0];
				
				for(var j in layer.features)
				{
					if(layer.features[j].cluster)
					{
						if(layer.features[j].cluster)
						{
							for(var k = 0; k < layer.features[j].cluster.length; k++)
							{
								if(layer.features[j].cluster[k].drupalFID && layer.features[j].cluster[k].drupalFID == id)
								{
									hoverControl = map.getControl('cmtls_map_feature_hover_control');
								}										
							}
						}
					}
					else if(layer.features[j].drupalFID && layer.features[j].drupalFID == id)
					{
						hoverControl = map.getControl('cmtls_map_feature_hover_control');
					}
					
					if(hoverControl)
					{
						hoverControl.select(layer.features[j]);
						return false;
					}
				}
			}
		});
		
		$('.cmtls-map-popup').live('mouseout', function ()
		{
			var id = this.id.replace('cmtls-map-feature-', '');
			
			var data = $('#openlayers-map-auto-id-0').data('openlayers');
			
			if (data && data.map.behaviors['cmtls_map_behavior_popup'])
			{
				var map = data.openlayers;
				var hoverControl = null
				var layer = map.getLayersByName('cmtls_features')[0];
				
				for(var j in layer.features)
				{
					if(layer.features[j].cluster)
					{
						if(layer.features[j].cluster)
						{
							for(var k = 0; k < layer.features[j].cluster.length; k++)
							{
								if(layer.features[j].cluster[k].drupalFID && layer.features[j].cluster[k].drupalFID == id)
								{
									hoverControl = map.getControl('cmtls_map_feature_hover_control');
								}										
							}
						}
					}
					else if(layer.features[j].drupalFID && layer.features[j].drupalFID == id)
					{
						hoverControl = map.getControl('cmtls_map_feature_hover_control');
					}
					
					if(hoverControl)
					{
						hoverControl.unselect(layer.features[j]);
						return false;
					}
				}
			}
		});
		
		$('.cmtls-map-popup').live('click', function ()
		{
			var id = this.id.replace('cmtls-map-feature-', '');
			
			var data = $('#openlayers-map-auto-id-0').data('openlayers');
			
			if (data && data.map.behaviors['cmtls_map_behavior_popup'])
			{
				var map = data.openlayers;
				var popupControl = null
				var layer = map.getLayersByName('cmtls_features')[0];
				
				for(var j in layer.features)
				{
					var k = 0;
					
					if(layer.features[j].cluster)
					{
						if(layer.features[j].cluster)
						{
							for(k = 0; k < layer.features[j].cluster.length; k++)
							{
								if(layer.features[j].cluster[k].drupalFID && layer.features[j].cluster[k].drupalFID == id)
								{
									popupControl = map.getControl('cmtls_map_pop_control');
									break;
								}										
							}
						}
					}
					else if(layer.features[j].drupalFID && layer.features[j].drupalFID == id)
					{
						popupControl = map.getControl('cmtls_map_pop_control');
					}
					
					if(popupControl)
					{
						popupControl.select(layer.features[j]);
						
						if(layer.features[j].cluster)
						{
							$('.cmtls-map-popup-content').addClass('hidden');
							$('#cmtls-map-popup-content-' + id).removeClass('hidden');
							
							$('#cmtls-map-popup-pager-' + layer.features[j].id.replace(/\./g, '-')).children('.cmtls-map-popup-pager-current').text(k + 1);
						}
						
						return false;
					}
				}
			}
			
			return false;
		});
	}
};

Drupal.behaviors.cmtls_map_behavior_add_object = function (context)
{
	if(context != window.document)
	{
		var data = $(context).data('openlayers');
		
		if (data && data.map.behaviors['cmtls_map_behavior_add_object'])
		{
			// OL control class for cmtls map tools
			OpenLayers.Control.Panel.CMTLSPanel = OpenLayers.Class(OpenLayers.Control.Panel,
			{
		    	autoActivate: true,
				redrawi: 0,
				redraw: function()
				{
					this.redrawi++;
					
					var $div = $(this.div);
					
					if (this.active)
					{
						for (var i = 0, len = this.controls.length; i < len; i++)
						{
							var control = this.controls[i];
							var $element = $(control.panel_div);
							
							if(this.redrawi == 1)
							{
								$element.text($element.attr('title'));
								
								if(control.ui_button_options)
								{
									$element.button(control.ui_button_options);
								}
								
								$div.append($element);
								$div.buttonset();
							}
						
							if (this.controls[i].active)
							{
								$element.addClass('selected');
							}
							else
							{
								$element.removeClass('selected');
							}    
						}
					}
				},
				
				CLASS_NAME: 'OpenLayers.Control.Panel.CMTLSPanel'
			});
			
			var map = data.openlayers;
			
			// layer to add features
			var layer = new OpenLayers.Layer.Vector(
				Drupal.t('Temporary Features Layer'),
				{
					projection: new OpenLayers.Projection('EPSG:4326'),
					styleMap: new OpenLayers.StyleMap({'default': data.map.styles.temporary})
				}
			);
			
			// add the feature adding layer to the map
			map.addLayer(layer);
			
			// event for adding a feature on the map
			layer.events.register('featureadded', this, function(args)
			{
				$('#cmtls-map-tooltip').remove();
				
				var coords = args.feature.geometry.getBounds().getCenterLonLat();
				var layer = args.object;
			
				coords.transform(
					layer.map.getProjectionObject(),
					new OpenLayers.Projection('EPSG:4326')
				);
				
				var $button = $('#add-node-button');
				
				if($button.length > 0)
				{
					var href = $button.attr('href');
					
					$button.attr('href', href + '?lat=' + coords.lat + '&lon=' + coords.lon);
					$button.click();
					
					$button.attr('href', href);
					
					//args.feature.destroyMarker();
					args.feature.destroy();
				}
			});
			
			// button for adding features
			var drawfeature_control = new OpenLayers.Control.DrawFeature(
				layer,
				OpenLayers.Handler.Point,
				{
					displayClass: 'olControlDrawFeaturePoint',
					title: Drupal.t('Add point'),
					ui_button_options: {icons: {primary:'ui-icon-plus'}}
				}
			);
			
			// when the add feature becomes active show tooltip
			drawfeature_control.events.register('activate', this, function (args)
			{
				$('div.olMapViewport').append('<div id="cmtls-map-tooltip">' + Drupal.t('Click on the map to add new point') + '</div>');
			});
			
			drawfeature_control.events.register('deactivate', this, function (args)
			{
				$('#cmtls-map-tooltip').remove();
			});
			
			// button to show the layer switcher
			var layersButton = new OpenLayers.Control(
			{
				type: OpenLayers.Control.TYPE_TOGGLE,
				title: Drupal.t('Layers'),
				ui_button_options: {icons: {primary:'ui-icon-grip-dotted-horizontal'}},
				displayClass: 'something-something',
				autoActivate: false,
				activate: function ()
				{
					//console.log('activate');
					$('#cmtls-map-layer-switcher').removeClass('hidden');
			        return OpenLayers.Control.prototype.activate.apply(this, arguments);
					
				},
				deactivate: function ()
				{
					//console.log('deactivate');
					$('#cmtls-map-layer-switcher').addClass('hidden');
			        return OpenLayers.Control.prototype.deactivate.apply(this, arguments);
				}
			});
			
			// the cmtls tools instance
			var panel = new OpenLayers.Control.Panel.CMTLSPanel();
			
			panel.addControls([new OpenLayers.Control.Navigation({title: Drupal.t('Move'), ui_button_options: {icons: {primary:'ui-icon-arrow-4'}}}), drawfeature_control, layersButton]);
			panel.defaultControl = panel.controls[0];
			
			data.openlayers.addControl(panel);
			
			// layer switcher tags toggle
			$('.cmtls-layer-switch-tag').live('change', function ()
			{
				var $this = $(this);
				var checked = $this.attr('checked');
				
				var data = $('#openlayers-map-auto-id-0').data('openlayers');
				
				if (data && data.map.behaviors['cmtls_map_behavior_popup'])
				{
					var map = data.openlayers;
					
					var layer = map.getLayersByName('cmtls_features')[0];
					
					if(layer.features)
					{
						var aid = $(this).attr('data-aid');
						var $tags = $('.cmtls-layer-switch-tag[data-aid="' + aid + '"][data-tid]');
						
						for(var i in layer.features)
						{
							var feature = layer.features[i];
							
							if(feature.attributes && feature.attributes.aid && feature.attributes.aid == aid && feature.attributes.taxonomy)
							{
								var taxonomy = feature.attributes.taxonomy;
								
								var show = true;
								
								for(var j in taxonomy)
								{
									if($tags.filter('[data-tid="' + j + '"]').attr('checked'))
									{
										show = true;
										break;
									}
									else
									{
										show = false;
									}
								}
								
								if(show && (feature.style.display != 'none' || feature.style.display != 'undefined'))
								{
									feature.style.display = 'block';
									layer.drawFeature(feature);
								}
								else if(feature.style.display == 'block' || feature.style.display != 'undefined')
								{
									feature.style.display = 'none';
									layer.drawFeature(feature);
								}
							}
						}
							
					}
				}
				
				return false;
			});
			
			// layer switcher app toggle
			$('.cmtls-layer-switch-app').live('change', function ()
			{
				var $this = $(this);
				var checked = $this.attr('checked');
				
				var data = $('#openlayers-map-auto-id-0').data('openlayers');
				
				if (data && data.map.behaviors['cmtls_map_behavior_popup'])
				{
					var map = data.openlayers;
					
					var layer = map.getLayersByName('cmtls_features')[0];
					
					if(layer.features)
					{
						var aid = $this.attr('data-aid');
						var $tags = $('.cmtls-layer-switch-tag[data-aid="' + aid + '"][data-tid]');
						
						for(var i in layer.features)
						{
							var feature = layer.features[i]
							if(feature.attributes && feature.attributes.aid && feature.attributes.aid == aid)
							{
								var show = true;
								
								if(checked && feature.attributes.taxonomy)
								{
									var taxonomy = feature.attributes.taxonomy;
									
									for(var j in taxonomy)
									{
										if($tags.filter('[data-tid="' + j + '"]').attr('checked'))
										{
											show = true;
											break;
										}
										else
										{
											show = false;
										}
									}
								}
								
								if(checked)
								{
									$tags.attr('disabled', false);
									if(show && (feature.style.display != 'none' || feature.style.display != 'undefined'))
									{
										feature.style.display = 'block';
										layer.drawFeature(feature);
									}
								}
								else
								{
									$tags.attr('disabled', true);
									if(feature.style.display == 'block' || feature.style.display != 'undefined')
									{
										feature.style.display = 'none';
										layer.drawFeature(feature);
									}
								}
							}
						}
					}
				}
				
				return false;
			});
		}
	}
}

function pagePopupContent(dir, element)
{
	var $this = $(element);
	
	var $pager = $this.parent();
	var popup_content_id = $pager.attr('id').replace('cmtls-map-popup-pager-', '');
	var $content = $('#cmtls-map-popup-contents-' + popup_content_id);
	
	$content.children('.cmtls-map-popup-content').each(function (index)
	{
		var $this = $(this);
		
		var page_guard = (dir == 'next' ? $this.siblings().length - 1 : 0);
		
		if(index == page_guard && !$this.hasClass('hidden')) return false;
		
		// this is the one displayed currently
		if(!$this.hasClass('hidden'))
		{
			$this.addClass('hidden');
			if(dir == 'next')
			{
				$this.next().removeClass('hidden');
			}
			else
			{
				$this.prev().removeClass('hidden');
			}
			$pager.children('.cmtls-map-popup-pager-current').text(index + (dir == 'next' ? 2 : 0));
			return false;
		}
	});
	
	return false;
}

function closePopup(element)
{
	var data = $('#openlayers-map-auto-id-0').data('openlayers');
	var map = data.openlayers;
	
	if (data && data.map.behaviors['cmtls_map_behavior_popup'])
	{
		// remove all other popups
		var popups = map.popups;
		var popups_length = popups.length;
		
		for(var i = 0; i < popups_length; i++)
		{
			map.removePopup(popups[i]);
		}
	}
}

function mapLocationSwitcer(className)
{
	$('#content').removeClass();
	$('#content').addClass(className);
	
	mapResize();	
}

function mapResize()
{
	var $map = $('#openlayers-map-auto-id-0');
	
	$content = $('#content');
	
	var olmap_width = $(window).width() - ($content.hasClass('map-only') ? 120 : 671);
	var olmap_height = $(window).height() - 100;
	
	if($content.hasClass('text-only'))
	{
		$('#text-container').width($(window).width() - 185);
	}
	else
	{
		$('#text-container').attr('style', '');
	}
	
	if($content.hasClass('text-map'))
	{
		$('#map').css('left', 170 + $content.width() + 'px');
	}
	else if($content.hasClass('map-only'))
	{
		$('#map').css('left', '120px');
	}
	
	if($map.data('openlayers'))
	{
		var map = $map.data('openlayers').openlayers;
		$map.width(olmap_width).height(olmap_height);
		
		map.updateSize();
	}
	else if($('#openlayers-container-openlayers-map-auto-id-0').length > 0 && Drupal && Drupal.settings && Drupal.settings.openlayers && Drupal.settings.openlayers.maps["openlayers-map-auto-id-0"])
	{
		$("#openlayers-container-openlayers-map-auto-id-0").attr("style", "width: " + olmap_width + "px; height: " + olmap_height + "px;");
		$("#openlayers-map-auto-id-0").attr("style", "width: " + olmap_width + "px; height: " + olmap_height + "px;");
		
		Drupal.settings.openlayers.maps["openlayers-map-auto-id-0"].height = olmap_height + "px";
		Drupal.settings.openlayers.maps["openlayers-map-auto-id-0"].width = olmap_width + "px";
		
		$('#openlayers-container-openlayers-map-auto-id-0').width(olmap_width).height(olmap_height);
		$('#openlayers-map-auto-id-0').width(olmap_width).height(olmap_height);
	}
}


