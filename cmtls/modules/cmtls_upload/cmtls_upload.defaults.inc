<?php

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _cmtls_upload_user_default_permissions() {
  $permissions = array();

  // Exported permission: upload files
  $permissions[] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: view uploaded files
  $permissions[] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
