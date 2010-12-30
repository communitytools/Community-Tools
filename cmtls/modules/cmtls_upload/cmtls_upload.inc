<?php

function cmtls_upload_transfer($parent=null){
	$args = func_get_args();

	$sid = $_POST['PHPSESSID'];
	$node_type = $_POST['nodetype'];
	$fieldname = $_POST['fieldname'];
	$parent = $parent!=null ? $parent->nid : $node_type;

	if(!$sid or !$node_type or !$fieldname){
		drupal_json(array('status'=>FALSE, 'data'=>t('Malformed data.')));
		exit;
	}

	// Fetch session from database
	$session = db_fetch_object(db_query("SELECT * FROM {sessions} WHERE sid = '%s' AND hostname = '%s'",$sid,ip_address()));

	if(!$session){
		drupal_access_denied();
		drupal_json(array('status'=>FALSE, 'data'=>t('Session has expired. Some more meaningful notification text here')));
		exit;
	}
	
	global $user;
	$user = user_load(array('uid'=>$session->uid));

	if(!node_access('create', (object)array('type' => 'cmtls_album_object'), $user)){
		drupal_access_denied();
		drupal_json(array('status'=>FALSE, data=>t('Not enough permissions. Some more meaningful notification text here')));
		exit;
	}

	// Adapt posted file array to Drupal's structure
	$_FILES['files']['name'][$fieldname] = $_FILES['Filedata']['name'];
	$_FILES['files']['type'][$fieldname] = $_FILES['Filedata']['type'];
	$_FILES['files']['tmp_name'][$fieldname] = $_FILES['Filedata']['tmp_name'];
	$_FILES['files']['error'][$fieldname] = $_FILES['Filedata']['error'];
	$_FILES['files']['size'][$fieldname] = $_FILES['Filedata']['size'];
	
	// Do some checks via transliteration module if available
	if (module_exists('transliteration')) {
		require_once(drupal_get_path('module', 'transliteration') .'/transliteration.inc');
		$_FILES['files']['name'][$fieldname] = transliteration_clean_filename($_FILES['Filedata']['name']);
	}

	// Cache the uploaded file for later processing
	cmtls_upload_cache_file($parent,$fieldname,$session);
}

/**
 * Caches uploaded file for processing later
 * 
 * @param Object $parent
 * @param String $node_type
 * @param String $fieldname
 * @return 
 */
function cmtls_upload_cache_file($parent,$fieldname,$session){
	// Save the file to the filesystem
	$file = file_save_upload($fieldname,array(),file_directory_path());

	// Save the file to cache table for easier tracking later
	$query = db_query("INSERT INTO {cache_cmtls_upload} (`fid`,`uid`,`parent`,`sid`) VALUES(%d,%d,%d,'%s')",$file->fid,$file->uid,$parent,$session->sid);
	
	if(!$query){
		//form_set_error();
	}else{
		// return great success
	}
}
