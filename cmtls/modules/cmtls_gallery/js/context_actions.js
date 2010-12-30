function cmtls_album_edit(){
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/album/' + node.nid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_album_delete(){
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/album/' + node.nid + '/delete';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_album_object_edit(){
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/album/' + Drupal.settings.cmtls.currentAlbum.nid + '/' + node.nid + '/edit';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}

function cmtls_album_object_delete(){
	var objectData = $(this).data('objectData');
	
	var node = JSON.parse($(objectData.anchor).attr('object'));
	
    var url = Drupal.settings.basePath + 'cmtls/' + Drupal.settings.cmtls.currentGroup.nid + '/' + node.nid + '/album/' + Drupal.settings.cmtls.currentAlbum.nid + '/' + node.nid + '/delete';
    
	Drupal.cmtls.instance.modalFrameOpen({url: url});
    
    // Prevent default action of the link click event.
    return false;
}