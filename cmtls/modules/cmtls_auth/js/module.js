jQuery(function($){
	/*
	 * Connect FB Account with local account form improvements
	 */
	$('#edit-registration-type-new-user').bind('change', function(event){
		$('#authentication-wrapper').slideUp(500);
	});
	
	$('#edit-registration-type-existing-user').bind('change', function(event){
		$('#authentication-wrapper').slideDown(500);
	});

	// Disable credentials fields by default
	if(!$('#edit-registration-type-existing-user').attr('checked')){
		$('#authentication-wrapper').hide();
	}
});

