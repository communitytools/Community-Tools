jQuery(function($){
	// Disable login button for starters
	jQuery('#edit-fb-integration')
		.attr('disabled', true)
		.addClass('disabled');

	// Load Facebook's JSDK asynchronously
	var e = document.createElement('script'); e.async = true;
	e.src = document.location.protocol + '//connect.facebook.net/en_US/all.js';
	$('#fb-root').append($(e));

	// Bind login event to button
	$('#edit-fb-integration').bind('click', function(event){
		if(!$(this).hasClass('disabled')){
			cmtlsFB.logUserIn();
		}

		return false;
	});
});

window.fbAsyncInit = function() {
	// Enable login button
	jQuery('#edit-fb-integration')
		.removeAttr('disabled')
		.removeClass('disabled');

	// Init Facebook
	FB.init({appId: Drupal.settings.cmtls.Facebook.appId, status: true, cookie: true, xfbml: false});

	// Subscribe to logout event
	FB.Event.subscribe('auth.logout', function(response){
		// TODO: Think of what should happen here
		//cmtlsFB.redirect(response.session);
	});
}

var cmtlsFB = cmtlsFB || {};

cmtlsFB.logUserIn = function(){
	// Get Facebook login status
	return FB.getLoginStatus(function(response){
		// If we don't have a session
		if(!response.session){
			// Try to log the user in with some extended permissions
			return FB.login(function(response){
				// If successful, redirect user to local authentication page
				if(response.session){
					cmtlsFB.redirect(response.session);
				}else{
					return false;
				}
			}, {perms: 'email'});
		// If we have a session, go directly to local authentication page
		}else{
			cmtlsFB.redirect(response.session);
		}
	});

}

cmtlsFB.logUserOut = function(){
	FB.logout();
}

cmtlsFB.redirect = function(session){
	if(session != null){
		window.location.href = Drupal.settings.basePath + 'cmtls/login/facebook';
	}
}