
function cmtls_member_edit()
{
	var objectData = $(this).data('objectData');
	
	var user = JSON.parse($(objectData.anchor).attr('user'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/member/' + user.uid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}

