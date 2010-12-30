<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_idea_taxonomy_default_vocabularies() {
  return array(
    'cmtls_idea_keywords' => array(
      'name' => 'Idea keywords',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '1',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_cmtls_idea_keywords',
      'weight' => '0',
      'nodes' => array(
        'cmtls_idea' => 'cmtls_idea',
      ),
    ),
  );
}
