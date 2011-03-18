<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_place_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_place content
  $permissions['create cmtls_place content'] = array(
    'name' => 'create cmtls_place content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_place content
  $permissions['delete any cmtls_place content'] = array(
    'name' => 'delete any cmtls_place content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_place content
  $permissions['delete own cmtls_place content'] = array(
    'name' => 'delete own cmtls_place content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_place content
  $permissions['edit any cmtls_place content'] = array(
    'name' => 'edit any cmtls_place content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_place_contact
  $permissions['edit field_cmtls_place_contact'] = array(
    'name' => 'edit field_cmtls_place_contact',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_place_email
  $permissions['edit field_cmtls_place_email'] = array(
    'name' => 'edit field_cmtls_place_email',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_place_phone
  $permissions['edit field_cmtls_place_phone'] = array(
    'name' => 'edit field_cmtls_place_phone',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_place_website
  $permissions['edit field_cmtls_place_website'] = array(
    'name' => 'edit field_cmtls_place_website',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_place content
  $permissions['edit own cmtls_place content'] = array(
    'name' => 'edit own cmtls_place content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_place_contact
  $permissions['view field_cmtls_place_contact'] = array(
    'name' => 'view field_cmtls_place_contact',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_place_email
  $permissions['view field_cmtls_place_email'] = array(
    'name' => 'view field_cmtls_place_email',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_place_phone
  $permissions['view field_cmtls_place_phone'] = array(
    'name' => 'view field_cmtls_place_phone',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_place_website
  $permissions['view field_cmtls_place_website'] = array(
    'name' => 'view field_cmtls_place_website',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_registration_open
  $permissions['view field_cmtls_registration_open'] = array(
    'name' => 'view field_cmtls_registration_open',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
