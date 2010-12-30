
Drupal.behaviors.cmtls_filter = function(context)
{
	if (context == window.document)
	{
		// Toggle Filters
		$(".content-filter-toggle a.button").click( function () {
			$(".content-filter-toggle a.button").toggleClass("selected");
			$("div.content-filter").slideToggle("fast");
		});

		// Clear keyword contents
		$("#edit-search").focus( function () {
			if (!edit_search_focused)
			{
				$("#edit-search").attr("value", "");
				edit_search_focused = true;
			}
		});

		$('#edit-submit').click( function ()	{
			if (!edit_search_focused)
			{
				$("#edit-search").attr("value", "");
				edit_search_focused = true;
			}
		});

	}
}
