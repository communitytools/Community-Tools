
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
				
				for(var i in map.layers)
				{
					if(map.layers[i].drupalID)
					{
						for(var j in map.layers[i].features)
						{
							if(map.layers[i].features[j].cluster)
							{
								if(map.layers[i].features[j].cluster)
								{
									for(var k = 0; k < map.layers[i].features[j].cluster.length; k++)
									{
										if(map.layers[i].features[j].cluster[k].drupalFID && map.layers[i].features[j].cluster[k].drupalFID == id)
										{
											hoverControl = map.getControl('cmtls_map_feature_hover_control');
										}										
									}
								}
							}
							else if(map.layers[i].features[j].drupalFID && map.layers[i].features[j].drupalFID == id)
							{
								hoverControl = map.getControl('cmtls_map_feature_hover_control');
							}
							
							if(hoverControl)
							{
								hoverControl.select(map.layers[i].features[j]);
								return false;
							}
						}
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
				
				for(var i in map.layers)
				{
					if(map.layers[i].drupalID)
					{
						for(var j in map.layers[i].features)
						{
							if(map.layers[i].features[j].cluster)
							{
								if(map.layers[i].features[j].cluster)
								{
									for(var k = 0; k < map.layers[i].features[j].cluster.length; k++)
									{
										if(map.layers[i].features[j].cluster[k].drupalFID && map.layers[i].features[j].cluster[k].drupalFID == id)
										{
											hoverControl = map.getControl('cmtls_map_feature_hover_control');
										}										
									}
								}
							}
							else if(map.layers[i].features[j].drupalFID && map.layers[i].features[j].drupalFID == id)
							{
								hoverControl = map.getControl('cmtls_map_feature_hover_control');
							}
							
							if(hoverControl)
							{
								hoverControl.unselect(map.layers[i].features[j]);
								return false;
							}
						}
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
				
				for(var i in map.layers)
				{
					if(map.layers[i].drupalID)
					{
						for(var j in map.layers[i].features)
						{
							var k = 0;
							
							if(map.layers[i].features[j].cluster)
							{
								if(map.layers[i].features[j].cluster)
								{
									for(k = 0; k < map.layers[i].features[j].cluster.length; k++)
									{
										if(map.layers[i].features[j].cluster[k].drupalFID && map.layers[i].features[j].cluster[k].drupalFID == id)
										{
											popupControl = map.getControl('cmtls_map_pop_control');
											break;
										}										
									}
								}
							}
							else if(map.layers[i].features[j].drupalFID && map.layers[i].features[j].drupalFID == id)
							{
								popupControl = map.getControl('cmtls_map_pop_control');
							}
							
							if(popupControl)
							{
								popupControl.select(map.layers[i].features[j]);
								
								if(map.layers[i].features[j].cluster)
								{
									$('.cmtls-map-popup-content').addClass('hidden');
									$('#cmtls-map-popup-content-' + id).removeClass('hidden');
									
									$('#cmtls-map-popup-pager-' + map.layers[i].features[j].id.replace(/\./g, '-')).children('.cmtls-map-popup-pager-current').text(k + 1);
								}
								
								return false;
							}
						}
					}
				}
			}
			
			return false;
		});
	}
};

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
	
	var olmap_width = $(window).width() - ($content.hasClass('map-only') ? 132 : 671);
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
		$('#map').css('left', '132px');
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