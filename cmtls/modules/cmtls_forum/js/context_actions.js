
function cmtls_forum_edit()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid + '/forum/' + node.nid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prforum default action of the link click forum.
    return false;
}

function cmtls_forum_moveup()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid + '/forum/' + node.nid + '/move/up?destination=cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid;
	
    window.location.href = url;
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_forum_movedown()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid + '/forum/' + node.nid + '/move/down?destination=cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid;
	
    window.location.href = url;
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_thread_edit()
{
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + Drupal.settings.cmtls.currentApp.nid + '/forum/' + Drupal.settings.cmtls.currentForum.nid + '/' + node.nid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prforum default action of the link click forum.
    return false;
}
