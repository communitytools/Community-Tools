<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_article_taxonomy_default_vocabularies() {
  return array(
    'cmtls_article_keywords' => array(
      'name' => 'Article keywords',
      'description' => 'Community Tools: Article keywords',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '1',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_cmtls_article_keywords',
      'weight' => '0',
      'nodes' => array(
        'cmtls_article' => 'cmtls_article',
      ),
    ),
  );
}
