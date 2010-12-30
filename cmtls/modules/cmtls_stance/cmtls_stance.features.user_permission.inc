<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_stance_user_default_permissions() {
  $permissions = array();

  // Exported permission: access cmtls stance
  $permissions['access cmtls stance'] = array(
    'name' => 'access cmtls stance',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
