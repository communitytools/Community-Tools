<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function cmtls_fb_imagecache_default_presets() {
  $items = array(
    'avatar_small' => array(
      'presetname' => 'avatar_small',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '55',
            'height' => '55',
          ),
        ),
      ),
    ),
  );
  return $items;
}
