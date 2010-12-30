<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_app_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_app content
  $permissions['create cmtls_app content'] = array(
    'name' => 'create cmtls_app content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_app content
  $permissions['delete any cmtls_app content'] = array(
    'name' => 'delete any cmtls_app content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_app content
  $permissions['delete own cmtls_app content'] = array(
    'name' => 'delete own cmtls_app content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_app content
  $permissions['edit any cmtls_app content'] = array(
    'name' => 'edit any cmtls_app content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_app_config
  $permissions['edit field_cmtls_app_config'] = array(
    'name' => 'edit field_cmtls_app_config',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_app_custom_view
  $permissions['edit field_cmtls_app_custom_view'] = array(
    'name' => 'edit field_cmtls_app_custom_view',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_app_type
  $permissions['edit field_cmtls_app_type'] = array(
    'name' => 'edit field_cmtls_app_type',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_app content
  $permissions['edit own cmtls_app content'] = array(
    'name' => 'edit own cmtls_app content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_app_config
  $permissions['view field_cmtls_app_config'] = array(
    'name' => 'view field_cmtls_app_config',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_app_custom_view
  $permissions['view field_cmtls_app_custom_view'] = array(
    'name' => 'view field_cmtls_app_custom_view',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_app_type
  $permissions['view field_cmtls_app_type'] = array(
    'name' => 'view field_cmtls_app_type',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
