<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_idea_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_idea content
  $permissions['create cmtls_idea content'] = array(
    'name' => 'create cmtls_idea content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_idea content
  $permissions['delete any cmtls_idea content'] = array(
    'name' => 'delete any cmtls_idea content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_idea content
  $permissions['delete own cmtls_idea content'] = array(
    'name' => 'delete own cmtls_idea content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_idea content
  $permissions['edit any cmtls_idea content'] = array(
    'name' => 'edit any cmtls_idea content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_idea_post_on_fb
  $permissions['edit field_cmtls_idea_post_on_fb'] = array(
    'name' => 'edit field_cmtls_idea_post_on_fb',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_idea_status
  $permissions['edit field_cmtls_idea_status'] = array(
    'name' => 'edit field_cmtls_idea_status',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_idea content
  $permissions['edit own cmtls_idea content'] = array(
    'name' => 'edit own cmtls_idea content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_idea_post_on_fb
  $permissions['view field_cmtls_idea_post_on_fb'] = array(
    'name' => 'view field_cmtls_idea_post_on_fb',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_idea_status
  $permissions['view field_cmtls_idea_status'] = array(
    'name' => 'view field_cmtls_idea_status',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
