<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_dashboard_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_dashboard content
  $permissions['create cmtls_dashboard content'] = array(
    'name' => 'create cmtls_dashboard content',
    'roles' => array(),
  );

  // Exported permission: delete any cmtls_dashboard content
  $permissions['delete any cmtls_dashboard content'] = array(
    'name' => 'delete any cmtls_dashboard content',
    'roles' => array(),
  );

  // Exported permission: delete own cmtls_dashboard content
  $permissions['delete own cmtls_dashboard content'] = array(
    'name' => 'delete own cmtls_dashboard content',
    'roles' => array(),
  );

  // Exported permission: edit any cmtls_dashboard content
  $permissions['edit any cmtls_dashboard content'] = array(
    'name' => 'edit any cmtls_dashboard content',
    'roles' => array(),
  );

  // Exported permission: edit own cmtls_dashboard content
  $permissions['edit own cmtls_dashboard content'] = array(
    'name' => 'edit own cmtls_dashboard content',
    'roles' => array(),
  );

  return $permissions;
}
