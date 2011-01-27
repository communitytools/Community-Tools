<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_place_taxonomy_default_vocabularies() {
  return array(
    'cmtls_place_keywords' => array(
      'name' => 'place keywords',
      'description' => 'Community Tools: Place keywords',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '1',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_cmtls_place_keywords',
      'weight' => '0',
      'nodes' => array(
        'cmtls_place' => 'cmtls_place',
      ),
    ),
  );
}
