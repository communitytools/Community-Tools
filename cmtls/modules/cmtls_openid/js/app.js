
Drupal.behaviors.cmtls_openid_login = function(context)
{
	if(context == window.document && $.browser.msie)
	{
		$('#edit-idcard-integration').click(function ()
		{
			$(this.form).attr('target', '_parent');
		});
	}
}
