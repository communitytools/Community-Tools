<?php

/**
 * Implementation of hook_strongarm().
 */
function cmtls_dashboard_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmtls_dashboard';
  $strongarm->value = 0;

  $export['comment_anonymous_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmtls_dashboard';
  $strongarm->value = '0';

  $export['comment_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_cmtls_dashboard';
  $strongarm->value = '3';

  $export['comment_controls_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmtls_dashboard';
  $strongarm->value = '4';

  $export['comment_default_mode_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_cmtls_dashboard';
  $strongarm->value = '1';

  $export['comment_default_order_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmtls_dashboard';
  $strongarm->value = '50';

  $export['comment_default_per_page_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmtls_dashboard';
  $strongarm->value = '0';

  $export['comment_form_location_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmtls_dashboard';
  $strongarm->value = '1';

  $export['comment_preview_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmtls_dashboard';
  $strongarm->value = '1';

  $export['comment_subject_field_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cmtls_dashboard';
  $strongarm->value = '0';

  $export['language_content_type_cmtls_dashboard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmtls_dashboard';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_cmtls_dashboard'] = $strongarm;
  return $export;
}
