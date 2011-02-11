
Drupal.behaviors.cmtls_idea_fb_publish = function(context)
{
	if(context == window.document)
	{
		// Load Facebook's JSDK asynchronously
		var e = document.createElement('script'); e.async = true;
		e.src = document.location.protocol + '//connect.facebook.net/en_US/all.js';
		$('#fb-root').append($(e));
	}
}

window.fbAsyncInit = function()
{
	// Init Facebook
	FB.init({appId: Drupal.settings.cmtls.Facebook.appId, status: true, cookie: true, xfbml: false});
	
	if (Drupal.settings.cmtls.Facebook.streamPublish)
	{
		
		FB.ui(Drupal.settings.cmtls.Facebook.streamPublish, function (response)
		{
			if(window.parent)
			{
				window.parent.document.location.replace(window.parent.document.location.href);
			}
		});
	}	
}
