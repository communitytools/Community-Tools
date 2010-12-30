<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _cmtls_forum_node_info() {
  $items = array(
    'cmtls_forum' => array(
      'name' => t('Community Tools: Forum'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'cmtls_thread' => array(
      'name' => t('Community Tools: Forum thread'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
