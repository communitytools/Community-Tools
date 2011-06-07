<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_member_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function cmtls_member_node_info() {
  $items = array(
    'cmtls_member' => array(
      'name' => t('Community Tools: Grupi liige'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Pealkiri'),
      'has_body' => '1',
      'body_label' => t('Kirjeldus'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cmtls_member_views_api() {
  return array(
    'api' => '2',
  );
}
