<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_forum_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_forum content
  $permissions['create cmtls_forum content'] = array(
    'name' => 'create cmtls_forum content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: create cmtls_thread content
  $permissions['create cmtls_thread content'] = array(
    'name' => 'create cmtls_thread content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_forum content
  $permissions['delete any cmtls_forum content'] = array(
    'name' => 'delete any cmtls_forum content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete any cmtls_thread content
  $permissions['delete any cmtls_thread content'] = array(
    'name' => 'delete any cmtls_thread content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_forum content
  $permissions['delete own cmtls_forum content'] = array(
    'name' => 'delete own cmtls_forum content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete own cmtls_thread content
  $permissions['delete own cmtls_thread content'] = array(
    'name' => 'delete own cmtls_thread content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_forum content
  $permissions['edit any cmtls_forum content'] = array(
    'name' => 'edit any cmtls_forum content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit any cmtls_thread content
  $permissions['edit any cmtls_thread content'] = array(
    'name' => 'edit any cmtls_thread content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own cmtls_forum content
  $permissions['edit own cmtls_forum content'] = array(
    'name' => 'edit own cmtls_forum content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_thread content
  $permissions['edit own cmtls_thread content'] = array(
    'name' => 'edit own cmtls_thread content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
