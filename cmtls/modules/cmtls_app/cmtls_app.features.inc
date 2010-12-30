<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_app_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function cmtls_app_node_info() {
  $items = array(
    'cmtls_app' => array(
      'name' => t('Community Tools: App'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cmtls_app_views_api() {
  return array(
    'api' => '2',
  );
}
