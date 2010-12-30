
Drupal.behaviors.cmtls_stance = function(context)
{
	if (context == window.document)
	{
		// Toggle Stance
		$('.stance-button').click(function()
		{
			$(this).nextAll('.stance-container').slideToggle('slow,');
			return false;
		});

		$('.stance-container form input[type="submit"]').remove();

		$('.stance-container form input[name="answer"]').live('click', function ()
		{
			var $this = $(this.form);
			var nid = $this.parents('.stance-container').attr('id').replace('stance-container-', '');

			$.ajax({
				type: $this.attr('method'),
				url: $this.attr('action'),
				dataType: 'json',
				data: $this.serialize() + '&ajax=1',
				success: function (data, textStatus, XMLHttpRequest)
				{
					if (data.content)
					{
						$('#stances-sorted-container-' + nid).html($(data.content).find('.stances-sorted-container').html());
					}
				},
				error: function (XMLHttpRequest, textStatus, errorThrown)
				{
					alert(textStatus);
				}
			});
		});
	}
}
