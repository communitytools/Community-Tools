
Drupal.behaviors.cmtls_event = function(context)
{
	if (context == window.document)
	{
		// checking dates
		dateFormat = 'dd.mm.yy';

		if ($('#edit-field-cmtls-event-lasts-all-day-value:checked').val() !== undefined)
		{
			$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1-wrapper').addClass('hidden');
			$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1-wrapper').addClass('hidden');
		}

		$('#edit-field-cmtls-event-lasts-all-day-value').bind('change', function ()
		{
			if ($('#edit-field-cmtls-event-lasts-all-day-value:checked').val() !== undefined)
			{
				$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1-wrapper').addClass('hidden');
				$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1-wrapper').addClass('hidden');
			}
			else
			{
				$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1-wrapper').removeClass('hidden');
				$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1-wrapper').removeClass('hidden');
			}
		});

		$('#node-form').bind('submit', function ()
		{
			if ($('#edit-field-cmtls-event-lasts-all-day-value:checked').val() !== undefined)
			{
				$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').attr('value', '00:00');
				$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').attr('value', '23:59');
			}
		});

		$('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').bind('change', function ()
		{
			fromDate = $.datepicker.parseDate(dateFormat, $(this).attr('value'));
			toDate = $.datepicker.parseDate(dateFormat, $('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').attr('value'));

			if (fromDate > toDate)
			{
				toDate = fromDate;
				$('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').attr('value', $.datepicker.formatDate(dateFormat, toDate));
			}
			else if (!(fromDate > toDate || toDate > fromDate))
			{
				fromTime = new Date(fromDate.toDateString() + ' ' + $('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').attr('value'));
				toTime = new Date(fromDate.toDateString() + ' ' + $('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').attr('value'));

				if (fromTime > toTime)
				{
					toTime = fromTime;
					toTime.setHours(toTime.getHours() + 1);

					if (toTime.getHours() < 1)
					{
						toDate.setDate(toDate.getDate() + 1);
						$('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').attr('value', $.datepicker.formatDate(dateFormat, toDate));
					}

					hour = toTime.getHours();
					if (hour < 10)
					{
						hour = '0' + hour;
					}

					minute = toTime.getMinutes();
					if (minute < 10)
					{
						minute = '0' + minute;
					}

					$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').attr('value', hour + ':' + minute);
				}
			}
		});

		$('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').bind('change', function ()
		{
			fromDate = $.datepicker.parseDate(dateFormat, $('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').attr('value'));
			toDate = $.datepicker.parseDate(dateFormat, $(this).attr('value'));

			if (toDate < fromDate)
			{
				fromDate = toDate;
				$('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').attr('value', $.datepicker.formatDate(dateFormat, fromDate));
			}
			else if (!(fromDate > toDate || toDate > fromDate))
			{
				fromTime = new Date(fromDate.toDateString() + ' ' + $('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').attr('value'));
				toTime = new Date(fromDate.toDateString() + ' ' + $('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').attr('value'));

				if (toTime < fromTime)
				{
					fromTime = toTime;
					fromTime.setHours(fromTime.getHours() - 1);

					if (fromTime.getHours() > 22)
					{
						fromDate.setDate(fromDate.getDate() - 1);
						$('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').attr('value', $.datepicker.formatDate(dateFormat, fromDate));
					}

					hour = fromTime.getHours();
					if (hour < 10)
					{
						hour = '0' + hour;
					}

					minute = fromTime.getMinutes();
					if (minute < 10)
					{
						minute = '0' + minute;
					}

					$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').attr('value', hour + ':' + minute);
				}
			}
		});

		$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').blur(function ()
		{
			fromDate = $.datepicker.parseDate(dateFormat, $('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').attr('value'));
			toDate = $.datepicker.parseDate(dateFormat, $('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').attr('value'));

			if (!(fromDate > toDate || toDate > fromDate))
			{
				fromTime = new Date(fromDate.toDateString() + ' ' + $(this).attr('value'));
				toTime = new Date(fromDate.toDateString() + ' ' + $('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').attr('value'));

				if (fromTime > toTime)
				{
					toTime = fromTime;
					toTime.setHours(toTime.getHours() + 1);

					if (toTime.getHours() < 1)
					{
						toDate.setDate(toDate.getDate() + 1);
						$('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').attr('value', $.datepicker.formatDate(dateFormat, toDate));
					}

					hour = toTime.getHours();
					if (hour < 10)
					{
						hour = '0' + hour;
					}

					minute = toTime.getMinutes();
					if (minute < 10)
					{
						minute = '0' + minute;
					}

					$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').attr('value', hour + ':' + minute);
				}
			}
		});

		$('#edit-field-cmtls-event-date-0-value2-timeEntry-popup-1').blur(function ()
		{
			fromDate = $.datepicker.parseDate(dateFormat, $('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').attr('value'));
			toDate = $.datepicker.parseDate(dateFormat, $('#edit-field-cmtls-event-date-0-value2-datepicker-popup-0').attr('value'));

			if (!(fromDate > toDate || toDate > fromDate))
			{
				fromTime = new Date(fromDate.toDateString() + ' ' + $('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').attr('value'));
				toTime = new Date(fromDate.toDateString() + ' ' + $(this).attr('value'));

				if (toTime < fromTime)
				{
					fromTime = toTime;
					fromTime.setHours(fromTime.getHours() - 1);

					if (fromTime.getHours() > 22)
					{
						fromDate.setDate(fromDate.getDate() - 1);
						$('#edit-field-cmtls-event-date-0-value-datepicker-popup-0').attr('value', $.datepicker.formatDate(dateFormat, fromDate));
					}

					hour = fromTime.getHours();
					if (hour < 10)
					{
						hour = '0' + hour;
					}

					minute = fromTime.getMinutes();
					if (minute < 10)
					{
						minute = '0' + minute;
					}

					$('#edit-field-cmtls-event-date-0-value-timeEntry-popup-1').attr('value', hour + ':' + minute);
				}
			}
		});


		// toggle events
		$('.event-toggle-container').hide();
	
		$('.event-toggle-button').live('click', function()
		{
			$(this).parent().next('.event-toggle-container').slideToggle('slow');
			return false;
		});
		
		// add calendar shifting
		$('#cmtls-horizontal-calendar-previous, #cmtls-horizontal-calendar-next').live('click', function()
		{
			shiftCalendar(this);
			
			return false;
		});
	}
}

function shiftCalendar(element)
{
	var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid + '/calendar/ajax';
	
	var data = $(element).attr('href').split('?');
	data = data[1] + '&ajax=1';
	
	$.ajax({
		type: 'GET',
		url: url,
		success: function (data, textStatus, XMLHttpRequest)
		{
			if(data.content)
			{
				$('#cmtls-horizontal-calendar-container').html(data.content);
			}
		},
		
		error: function (XMLHttpRequest, textStatus, errorThrown)
		{
			alert(textStatus);
		},
		dataType: 'json',
		data: data,
	});
}