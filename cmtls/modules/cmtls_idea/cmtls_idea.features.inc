<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_idea_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function cmtls_idea_node_info() {
  $items = array(
    'cmtls_idea' => array(
      'name' => t('Community Tools: Idea'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Pealkiri'),
      'has_body' => '1',
      'body_label' => t('Tekst'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cmtls_idea_views_api() {
  return array(
    'api' => '2',
  );
}
