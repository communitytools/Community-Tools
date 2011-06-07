
Drupal.behaviors.cmtls_stuff = function(context)
{
	if (context == window.document)
	{
		$('#cmtls-stuff-request-form-days-select').change( function ()
		{
			$('#cmtls-stuff-request-form-days').html($(this).children('option:selected').text());
		});
	}
}
