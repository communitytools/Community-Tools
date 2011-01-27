// $Id: $

Drupal.behaviors.cmtlsModalFrame = function(context)
{
	if(context = window.document)
	{
		$('.modalframe-child').live('click', function ()
		{
			var element = this;

			// Build modal frame options.
			var modalOptions = {
				url: $(element).attr('href'),
				autoFit: $(element).attr('modal_frame_autofit') ? $(element).attr('modal_frame_autofit') : true,
				width: $(element).attr('modal_frame_width') ? $(element).attr('modal_frame_width') * 1 : 600,
				height: $(element).attr('modal_frame_height') ? $(element).attr('modal_frame_height') * 1 : 200,
				onSubmit: $(element).attr('modal_frame_onsubmit') ? $(element).attr('modal_frame_onsubmit') : Drupal.cmtls.instance.modalFrameCallback
			};

			// Open the modal frame dialog.
			Drupal.modalFrame.open(modalOptions);

			// Prevent default action of the link click event.
			return false;
		});
	}

};

// cmtls js object
Drupal.cmtls = function ()
{
	this.init = function ()
	{
		// init the context menus
		$('.context_anchor').contextMenu();

		// jQuery UI common stuff
		$('.cmtls-button, input.form-submit').livequery(function(){
			$(this).button();
		});
		$('.cmtls-button-add').button({icons: {primary:'ui-icon-plus'}});
		$('.cmtls-button-filter').button({icons: {primary:'ui-icon-triangle-1-s'}});

		$.extend(Drupal.cmtls.instance.modalFrameOptions, {onSubmit: Drupal.cmtls.instance.modalFrameCallback});

		// register the default page reload callback function
		this.registerModalFrameCallback('refresh', function ()
		{
			document.location.replace(document.location.href);
		});

		// register the message callback function
		this.registerModalFrameCallback('message', function (message)
		{
			alert(message);
		});

		// register general redirect callback
		this.registerModalFrameCallback('redirect', function(path)
		{
			window.location.replace(path);
		});

		// transform timestamps into human readable dates
		$('span.unix-timestamp').each(function (index)
		{
			var currentDate = new Date();
			var date = new Date();
			date.setTime($(this).text() * 1000);

			var formatted = '';

			if(date.getFullYear() != currentDate.getFullYear())
			{
				formatted += date.getFullYear() + '.';
			}

			if(!(date.getMonth() == currentDate.getMonth() && date.getDate() == currentDate.getDate()))
			{
				var month = date.getMonth() + 1;
				var day = date.getDate();
				formatted += (day > 9 ? day : '0' + day) + '.' + (month > 9 ? month : '0' + month) + ' ';
			}

			var hours = date.getHours();
			var minutes = date.getMinutes();

			formatted += (hours > 9 ? hours : '0' + hours) + ':' + (minutes > 9 ? minutes : '0' + minutes);

			$(this).text(formatted);
			$(this).show();
		});

		this.paging();
	}

    this.modalFrameOptions = {
    	autoFit: true,
	    width: 600,
	    height: 200
    };

	this.modalFrameCallback = function(args, statusMessages)
	{
		if (args)
		{
			for(var i in args)
			{
				Drupal.cmtls.instance.modalFrameCallbacks[i](args[i]);
			}
		}
	}

	this.modalFrameOpen = function (options)
	{
		var defaultOptions = this.modalFrameOptions;

		options = $.extend(defaultOptions, options);

		// Open the modal frame dialog.
		Drupal.modalFrame.open(options);
	}

	this.modalFrameCallbacks = [];

	this.registerModalFrameCallback = function (name, callback)
	{
		this.modalFrameCallbacks[name] = callback;
	}

	this.paging = function()
	{
		if(Drupal.settings.cmtls.pager)
		{
			var nextPage = Drupal.settings.cmtls.pager.currentPage + 1;

			if(nextPage < Drupal.settings.cmtls.pager.totalPages)
			{
				$('#cmtls-pager-more-items-count').text(Drupal.settings.cmtls.pager.totalItems - (nextPage * Drupal.settings.cmtls.pager.itemsPerPage));
				$('#cmtls-pager').removeClass('hidden');

				$('#cmtls-pager-more-button').click(function ()
				{
					$('#cmtls-pager-more-button').addClass('hidden');
					$('#cmtls-pager-loading').removeClass('hidden');

					$.ajax({
						type: 'POST',
						url: this.href,
						success: function (data, textStatus, XMLHttpRequest)
						{
							if(data.content)
							{
								$('#cmtls-content-container-append').append(data.content);

								// init the context menus
								$('.context_anchor').contextMenu();

								nextPage++;

								if(nextPage < Drupal.settings.cmtls.pager.totalPages)
								{
									var href = $('#cmtls-pager-more-button').attr('href');
									$('#cmtls-pager-more-button').attr('href', href.replace(/page[0..9]*(?:=[^&]*)/, 'page=' + nextPage));
									$('#cmtls-pager-more-items-count').text(Drupal.settings.cmtls.pager.totalItems - (nextPage * Drupal.settings.cmtls.pager.itemsPerPage));
								}
								else
								{
									$('#cmtls-pager').addClass('hidden');
								}
							}

							// TODO: this function should be in cmtls_map module
							if(data.features)
							{
								var map = $('#openlayers-map-auto-id-0').data('openlayers');

								if(map)
								{
									map = map.openlayers;

									var features = [];

									for(var i in data.features)
									{
										var layerKey = data.features[i].attributes.layer;
										if(typeof(features[layerKey]) == "undefined") features[layerKey] = {};

										features[layerKey][i] = data.features[i];
									}

									for(var i in map.layers)
									{
										if(map.layers[i].drupalID && features[map.layers[i].drupalID])
										{
											//console.log(map.layers[i].strategies);
											//var cluster = map.layers[i].strategies[0];

											//cluster.deactivate();
											//map.layers[i].redraw(true);
											//cluster.clearCache();

											Drupal.openlayers.addFeatures(map, map.layers[i], features[map.layers[i].drupalID]);
											Drupal.behaviors.openlayers_zoomtolayer($('#openlayers-map-auto-id-0'));

											//cluster.features = map.layers[i].features.slice();
											//cluster.activate();
											//cluster.cluster();
										}
									}
								}
							}

							$('#cmtls-pager-more-button').removeClass('hidden');
							$('#cmtls-pager-loading').addClass('hidden');
						},
						error: function (XMLHttpRequest, textStatus, errorThrown)
						{
							$('#cmtls-pager-loading').addClass('hidden');
							alert(textStatus);
						},
						dataType: 'json',
						data: {ajax: 1}
					});

					return false;
				});
			}
		}
	}
}

// cmtls instance
Drupal.cmtls.instance = new Drupal.cmtls();

Drupal.behaviors.cmtls = function (context)
{
	if(context == window.document)
	{
		Drupal.cmtls.instance.init();
	}
};
