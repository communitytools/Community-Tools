<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_event content
  $permissions['create cmtls_event content'] = array(
    'name' => 'create cmtls_event content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete own cmtls_event content
  $permissions['delete own cmtls_event content'] = array(
    'name' => 'delete own cmtls_event content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_event content
  $permissions['edit any cmtls_event content'] = array(
    'name' => 'edit any cmtls_event content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_event_date
  $permissions['edit field_cmtls_event_date'] = array(
    'name' => 'edit field_cmtls_event_date',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_event_lasts_all_day
  $permissions['edit field_cmtls_event_lasts_all_day'] = array(
    'name' => 'edit field_cmtls_event_lasts_all_day',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_files
  $permissions['edit field_cmtls_files'] = array(
    'name' => 'edit field_cmtls_files',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_event content
  $permissions['edit own cmtls_event content'] = array(
    'name' => 'edit own cmtls_event content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_event_date
  $permissions['view field_cmtls_event_date'] = array(
    'name' => 'view field_cmtls_event_date',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_event_lasts_all_day
  $permissions['view field_cmtls_event_lasts_all_day'] = array(
    'name' => 'view field_cmtls_event_lasts_all_day',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_files
  $permissions['view field_cmtls_files'] = array(
    'name' => 'view field_cmtls_files',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
