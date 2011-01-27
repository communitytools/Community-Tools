<?php

/**
 * Implementation of hook_strongarm().
 */
function cmtls_event_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmtls_event';
  $strongarm->value = 0;

  $export['comment_anonymous_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmtls_event';
  $strongarm->value = '2';

  $export['comment_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_cmtls_event';
  $strongarm->value = '3';

  $export['comment_controls_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmtls_event';
  $strongarm->value = '1';

  $export['comment_default_mode_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_cmtls_event';
  $strongarm->value = '1';

  $export['comment_default_order_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmtls_event';
  $strongarm->value = '50';

  $export['comment_default_per_page_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmtls_event';
  $strongarm->value = '0';

  $export['comment_form_location_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmtls_event';
  $strongarm->value = '0';

  $export['comment_preview_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmtls_event';
  $strongarm->value = '1';

  $export['comment_subject_field_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_cmtls_event';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '2',
    'author' => '3',
    'options' => '4',
    'comment_settings' => '5',
    'menu' => '0',
    'taxonomy' => '-2',
    'path' => '6',
    'attachments' => '7',
    'og_nodeapi' => '1',
  );

  $export['content_extra_weights_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fbconnect_cmtls_event_onoff';
  $strongarm->value = 0;

  $export['fbconnect_cmtls_event_onoff'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cmtls_event';
  $strongarm->value = '0';

  $export['language_content_type_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_child_cmtls_event';
  $strongarm->value = 1;

  $export['nh_child_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_createmenu_cmtls_event';
  $strongarm->value = 'never';

  $export['nh_createmenu_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_defaultparent_cmtls_event';
  $strongarm->value = '0';

  $export['nh_defaultparent_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_parent_cmtls_event';
  $strongarm->value = 0;

  $export['nh_parent_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmtls_event';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_cmtls_event';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_cmtls_event';
  $strongarm->value = '';

  $export['og_max_groups_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'onoff_cmtls_event';
  $strongarm->value = 0;

  $export['onoff_cmtls_event'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_cmtls_event';
  $strongarm->value = '1';

  $export['upload_cmtls_event'] = $strongarm;
  return $export;
}
