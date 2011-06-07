<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_stuff_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_stuff content
  $permissions['create cmtls_stuff content'] = array(
    'name' => 'create cmtls_stuff content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_stuff content
  $permissions['delete any cmtls_stuff content'] = array(
    'name' => 'delete any cmtls_stuff content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_stuff content
  $permissions['delete own cmtls_stuff content'] = array(
    'name' => 'delete own cmtls_stuff content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_stuff content
  $permissions['edit any cmtls_stuff content'] = array(
    'name' => 'edit any cmtls_stuff content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_stuff_loan_date
  $permissions['edit field_cmtls_stuff_loan_date'] = array(
    'name' => 'edit field_cmtls_stuff_loan_date',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_stuff_loan_uid
  $permissions['edit field_cmtls_stuff_loan_uid'] = array(
    'name' => 'edit field_cmtls_stuff_loan_uid',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_stuff content
  $permissions['edit own cmtls_stuff content'] = array(
    'name' => 'edit own cmtls_stuff content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_stuff_loan_date
  $permissions['view field_cmtls_stuff_loan_date'] = array(
    'name' => 'view field_cmtls_stuff_loan_date',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_stuff_loan_uid
  $permissions['view field_cmtls_stuff_loan_uid'] = array(
    'name' => 'view field_cmtls_stuff_loan_uid',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
