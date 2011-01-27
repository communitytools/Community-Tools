
Drupal.behaviors.cmtls_filter = function(context)
{
	if (context == window.document)
	{
		// Toggle Filters
		$('.cmtls-button-filter').click( function () {
			$('div.content-filter').slideToggle('fast');
		});
	}
}
