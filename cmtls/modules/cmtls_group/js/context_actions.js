
function cmtls_group_edit()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + node.nid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prgroup default action of the link click group.
    return false;
}

