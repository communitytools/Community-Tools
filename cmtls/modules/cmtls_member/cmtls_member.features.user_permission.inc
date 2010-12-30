<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_member_user_default_permissions() {
  $permissions = array();

  // Exported permission: view imagecache avatar_small
  $permissions['view imagecache avatar_small'] = array(
    'name' => 'view imagecache avatar_small',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
