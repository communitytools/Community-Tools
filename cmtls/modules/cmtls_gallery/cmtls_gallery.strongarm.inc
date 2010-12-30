<?php

/**
 * Implementation of hook_strongarm().
 */
function cmtls_gallery_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmtls_album';
  $strongarm->value = 0;

  $export['comment_anonymous_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmtls_album_object';
  $strongarm->value = 0;

  $export['comment_anonymous_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmtls_album';
  $strongarm->value = '0';

  $export['comment_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmtls_album_object';
  $strongarm->value = '0';

  $export['comment_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_cmtls_album';
  $strongarm->value = '3';

  $export['comment_controls_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_cmtls_album_object';
  $strongarm->value = '3';

  $export['comment_controls_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmtls_album';
  $strongarm->value = '4';

  $export['comment_default_mode_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmtls_album_object';
  $strongarm->value = '4';

  $export['comment_default_mode_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_cmtls_album';
  $strongarm->value = '1';

  $export['comment_default_order_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_cmtls_album_object';
  $strongarm->value = '1';

  $export['comment_default_order_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmtls_album';
  $strongarm->value = '50';

  $export['comment_default_per_page_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmtls_album_object';
  $strongarm->value = '50';

  $export['comment_default_per_page_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmtls_album';
  $strongarm->value = '0';

  $export['comment_form_location_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmtls_album_object';
  $strongarm->value = '0';

  $export['comment_form_location_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmtls_album';
  $strongarm->value = '1';

  $export['comment_preview_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmtls_album_object';
  $strongarm->value = '1';

  $export['comment_preview_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmtls_album';
  $strongarm->value = '1';

  $export['comment_subject_field_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmtls_album_object';
  $strongarm->value = '1';

  $export['comment_subject_field_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_child_cmtls_album';
  $strongarm->value = 1;

  $export['nh_child_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_child_cmtls_album_object';
  $strongarm->value = 1;

  $export['nh_child_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_createmenu_cmtls_album';
  $strongarm->value = 'never';

  $export['nh_createmenu_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_createmenu_cmtls_album_object';
  $strongarm->value = 'never';

  $export['nh_createmenu_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_defaultparent_cmtls_album';
  $strongarm->value = '0';

  $export['nh_defaultparent_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_defaultparent_cmtls_album_object';
  $strongarm->value = '0';

  $export['nh_defaultparent_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_parent_cmtls_album';
  $strongarm->value = 1;

  $export['nh_parent_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nh_parent_cmtls_album_object';
  $strongarm->value = 0;

  $export['nh_parent_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmtls_album';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmtls_album_object';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_cmtls_album';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_cmtls_album_object';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_cmtls_album';
  $strongarm->value = '';

  $export['og_max_groups_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_cmtls_album_object';
  $strongarm->value = '';

  $export['og_max_groups_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'onoff_cmtls_album';
  $strongarm->value = 0;

  $export['onoff_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'onoff_cmtls_album_object';
  $strongarm->value = 0;

  $export['onoff_cmtls_album_object'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_cmtls_album';
  $strongarm->value = '1';

  $export['upload_cmtls_album'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_cmtls_album_object';
  $strongarm->value = '1';

  $export['upload_cmtls_album_object'] = $strongarm;
  return $export;
}
