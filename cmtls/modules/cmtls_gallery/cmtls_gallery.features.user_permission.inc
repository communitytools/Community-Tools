<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_gallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_album content
  $permissions['create cmtls_album content'] = array(
    'name' => 'create cmtls_album content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: create cmtls_album_object content
  $permissions['create cmtls_album_object content'] = array(
    'name' => 'create cmtls_album_object content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any cmtls_album content
  $permissions['delete any cmtls_album content'] = array(
    'name' => 'delete any cmtls_album content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete any cmtls_album_object content
  $permissions['delete any cmtls_album_object content'] = array(
    'name' => 'delete any cmtls_album_object content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own cmtls_album content
  $permissions['delete own cmtls_album content'] = array(
    'name' => 'delete own cmtls_album content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete own cmtls_album_object content
  $permissions['delete own cmtls_album_object content'] = array(
    'name' => 'delete own cmtls_album_object content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any cmtls_album content
  $permissions['edit any cmtls_album content'] = array(
    'name' => 'edit any cmtls_album content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit any cmtls_album_object content
  $permissions['edit any cmtls_album_object content'] = array(
    'name' => 'edit any cmtls_album_object content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit field_cmtls_cover_image
  $permissions['edit field_cmtls_cover_image'] = array(
    'name' => 'edit field_cmtls_cover_image',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_date
  $permissions['edit field_cmtls_date'] = array(
    'name' => 'edit field_cmtls_date',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_description
  $permissions['edit field_cmtls_description'] = array(
    'name' => 'edit field_cmtls_description',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_image_cover
  $permissions['edit field_cmtls_image_cover'] = array(
    'name' => 'edit field_cmtls_image_cover',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_cmtls_upload
  $permissions['edit field_cmtls_upload'] = array(
    'name' => 'edit field_cmtls_upload',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_album content
  $permissions['edit own cmtls_album content'] = array(
    'name' => 'edit own cmtls_album content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit own cmtls_album_object content
  $permissions['edit own cmtls_album_object content'] = array(
    'name' => 'edit own cmtls_album_object content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_cover_image
  $permissions['view field_cmtls_cover_image'] = array(
    'name' => 'view field_cmtls_cover_image',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_date
  $permissions['view field_cmtls_date'] = array(
    'name' => 'view field_cmtls_date',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_description
  $permissions['view field_cmtls_description'] = array(
    'name' => 'view field_cmtls_description',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_image_cover
  $permissions['view field_cmtls_image_cover'] = array(
    'name' => 'view field_cmtls_image_cover',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_cmtls_upload
  $permissions['view field_cmtls_upload'] = array(
    'name' => 'view field_cmtls_upload',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache full
  $permissions['view imagecache full'] = array(
    'name' => 'view imagecache full',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache thumbnail
  $permissions['view imagecache thumbnail'] = array(
    'name' => 'view imagecache thumbnail',
    'roles' => array(
      '0' => 'admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
