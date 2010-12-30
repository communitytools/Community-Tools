
function cmtls_app_edit()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_app_delete()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/delete';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_app_moveup()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/move/up?destination=cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid;
	
    window.location.href = url;
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_app_movedown()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/move/down?destination=cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid;
	
    window.location.href = url;
    
    // Prevent default action of the link click event.
    return false;
}

