<?php

/**
 * Implementation of hook_views_default_views().
 */
function cmtls_app_views_default_views() {
  $views = array();

  // Exported view: cmtls_apps
  $view = new view;
  $view->name = 'cmtls_apps';
  $view->description = 'Community Tools: Apps';
  $view->tag = 'cmtls';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => 'Title',
      'link_to_node' => 1,
    ),
    'parent' => array(
      'label' => 'Parent Node',
      'alter' => array(
        'alter_text' => FALSE,
        'text' => '',
        'make_link' => FALSE,
        'path' => '',
        'alt' => '',
        'link_class' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'trim' => FALSE,
        'max_length' => '',
        'word_boundary' => TRUE,
        'ellipsis' => TRUE,
        'strip_tags' => FALSE,
        'html' => FALSE,
      ),
      'empty' => '',
      'hide_empty' => FALSE,
      'empty_zero' => FALSE,
      'link_to_parent' => 1,
      'display_as' => 'title',
      'exclude' => '',
      'id' => 'parent',
      'table' => 'nodehierarchy',
      'field' => 'parent',
      'relationship' => 'none',
    ),
    'nid' => array(
      'label' => 'Nid',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'order_by' => array(
      'id' => 'order_by',
      'table' => 'nodehierarchy',
      'field' => 'order_by',
      'order' => 'ASC',
    ),
  ));
  $handler->override_option('arguments', array(
    'parent' => array(
      'id' => 'parent',
      'table' => 'nodehierarchy',
      'field' => 'parent',
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'operator' => '=',
      'value' => 1,
      'group' => 0,
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'expose_button' => array(
        'button' => 'Expose',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'access content',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $handler->override_option('row_options', array(
    'teaser' => 1,
  ));

  $views[$view->name] = $view;

  return $views;
}
