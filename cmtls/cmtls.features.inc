<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function cmtls_imagecache_default_presets() {
  $items = array(
    'content' => array(
      'presetname' => 'content',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '500',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'original' => array(
      'presetname' => 'original',
      'actions' => array(),
    ),
    'small' => array(
      'presetname' => 'small',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '52',
            'height' => '52',
          ),
        ),
      ),
    ),
  );
  return $items;
}
