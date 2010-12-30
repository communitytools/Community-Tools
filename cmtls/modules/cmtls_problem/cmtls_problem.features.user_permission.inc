<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_problem_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_problem content
  $permissions['create cmtls_problem content'] = array(
    'name' => 'create cmtls_problem content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_problem content
  $permissions['delete any cmtls_problem content'] = array(
    'name' => 'delete any cmtls_problem content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_problem content
  $permissions['delete own cmtls_problem content'] = array(
    'name' => 'delete own cmtls_problem content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_problem content
  $permissions['edit any cmtls_problem content'] = array(
    'name' => 'edit any cmtls_problem content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_problem_status
  $permissions['edit field_cmtls_problem_status'] = array(
    'name' => 'edit field_cmtls_problem_status',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_status_uid
  $permissions['edit field_cmtls_status_uid'] = array(
    'name' => 'edit field_cmtls_status_uid',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own cmtls_problem content
  $permissions['edit own cmtls_problem content'] = array(
    'name' => 'edit own cmtls_problem content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_problem_status
  $permissions['view field_cmtls_problem_status'] = array(
    'name' => 'view field_cmtls_problem_status',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_status_uid
  $permissions['view field_cmtls_status_uid'] = array(
    'name' => 'view field_cmtls_status_uid',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
