
function cmtls_place_edit()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid + '/place/' + node.nid + '/edit';
    
    Drupal.cmtls.instance.modalFrameOpen({url: url, width: 820});
    
    // Prevent default action of the link click event.
    return false;
}

