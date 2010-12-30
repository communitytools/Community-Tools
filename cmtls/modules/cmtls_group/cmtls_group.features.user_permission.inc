<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_group_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_group content
  $permissions['create cmtls_group content'] = array(
    'name' => 'create cmtls_group content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_group content
  $permissions['delete any cmtls_group content'] = array(
    'name' => 'delete any cmtls_group content',
    'roles' => array(),
  );

  // Exported permission: delete own cmtls_group content
  $permissions['delete own cmtls_group content'] = array(
    'name' => 'delete own cmtls_group content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_group content
  $permissions['edit any cmtls_group content'] = array(
    'name' => 'edit any cmtls_group content',
    'roles' => array(),
  );

  // Exported permission: edit field_cmtls_address
  $permissions['edit field_cmtls_address'] = array(
    'name' => 'edit field_cmtls_address',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_geoinfo
  $permissions['edit field_cmtls_geoinfo'] = array(
    'name' => 'edit field_cmtls_geoinfo',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_group_background
  $permissions['edit field_cmtls_group_background'] = array(
    'name' => 'edit field_cmtls_group_background',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_group_main
  $permissions['edit field_cmtls_group_main'] = array(
    'name' => 'edit field_cmtls_group_main',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_group_posting
  $permissions['edit field_cmtls_group_posting'] = array(
    'name' => 'edit field_cmtls_group_posting',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_group content
  $permissions['edit own cmtls_group content'] = array(
    'name' => 'edit own cmtls_group content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_address
  $permissions['view field_cmtls_address'] = array(
    'name' => 'view field_cmtls_address',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_geoinfo
  $permissions['view field_cmtls_geoinfo'] = array(
    'name' => 'view field_cmtls_geoinfo',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_group_background
  $permissions['view field_cmtls_group_background'] = array(
    'name' => 'view field_cmtls_group_background',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_group_main
  $permissions['view field_cmtls_group_main'] = array(
    'name' => 'view field_cmtls_group_main',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_group_posting
  $permissions['view field_cmtls_group_posting'] = array(
    'name' => 'view field_cmtls_group_posting',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
