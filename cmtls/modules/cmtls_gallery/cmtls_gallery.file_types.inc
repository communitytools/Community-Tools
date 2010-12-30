<?php

function cmtls_gallery_get_file_type_map(){
	/**
	 * Structure:
	 * <file extension>
	 * 		* type: <image|document|video|audio>
	 * 		* icon: name of the file in ./gfx/icons/ to replace default icon for current file type
	 * 		* playable: boolean
	 * 			Applies to audio/video files which should be played by flash widget
	 * 
	 * Examples:
	 * 'pdf'=>array(
	 * 		'type'=>'document',
	 * 		'icon'=>'my-custom-icon-for-pdf.png',
	 * )
	 * 
	 * 'mp3'=>array(
	 * 		'type'=>'audio',
	 * 		'playable'=>TRUE,
	 * )
	 */
	return array(
		'default'=>array(),
		'jpg'=>array(
			'type'=>'image'
		),
		'jpeg'=>array(
			'type'=>'image'
		),
		'gif'=>array(
			'type'=>'image'
		),
		'png'=>array(
			'type'=>'image'
		),
		'bmp'=>array(
			'type'=>'image'
		),
		'doc'=>array(
			'type'=>'document'
		),
		'xls'=>array(
			'type'=>'document'
		),
		'ppt'=>array(
			'type'=>'document'
		),
		'ods'=>array(
			'type'=>'document'
		),
		'odt'=>array(
			'type'=>'document'
		),
		'odp'=>array(
			'type'=>'document'
		),
		'pdf'=>array(
			'icon'=>'pdf.png',
			'type'=>'document'
		),
		'zip'=>array(
			'icon'=>'zip.png',
			'type'=>'archive'
		),
		'gzip'=>array(
			'icon'=>'gzip.png',
			'type'=>'archive'
		),
		'rar'=>array(
			'icon'=>'rar.png',
			'type'=>'archive'
		),
		'txt'=>array(
			'icon'=>'txt.png',
			'type'=>'document'
		),
		'avi'=>array(
			'type'=>'video'
		),
		'mpg'=>array(
			'type'=>'video'
		),
		'mpeg'=>array(
			'type'=>'video'
		),
		'flv'=>array(
			'type'=>'video',
			'playable'=>TRUE
		),
		'mp3'=>array(
			'type'=>'audio',
			'playable'=>TRUE
		),
		'mp4'=>array(
			'type'=>'video'
		),
	);
}
