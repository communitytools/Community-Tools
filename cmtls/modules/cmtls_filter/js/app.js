
Drupal.behaviors.cmtls_filter = function(context)
{
	if (context == window.document)
	{
		// Toggle Filters
		$('.content-filter-toggle a.button').click( function () {
			$('.content-filter-toggle a.button').toggleClass('selected');
			$('div.content-filter').slideToggle('fast');
		});
	}
}
