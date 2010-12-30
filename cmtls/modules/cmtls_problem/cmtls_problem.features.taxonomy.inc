<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_problem_taxonomy_default_vocabularies() {
  return array(
    'cmtls_problem_keywords' => array(
      'name' => 'Problem keyword',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_cmtls_problem_keywords',
      'weight' => '0',
      'nodes' => array(
        'cmtls_problem' => 'cmtls_problem',
      ),
    ),
  );
}
