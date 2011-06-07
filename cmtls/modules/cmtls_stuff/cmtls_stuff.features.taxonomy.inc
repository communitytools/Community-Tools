<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_stuff_taxonomy_default_vocabularies() {
  return array(
    'cmtls_stuff_keywords' => array(
      'name' => 'Stuff keywords',
      'description' => 'Community Tools: Stuff keywords',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '1',
      'required' => '1',
      'tags' => '1',
      'module' => 'features_cmtls_stuff_keywords',
      'weight' => '0',
      'nodes' => array(
        'cmtls_stuff' => 'cmtls_stuff',
      ),
    ),
  );
}
