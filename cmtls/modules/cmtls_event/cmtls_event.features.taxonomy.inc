<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cmtls_event_taxonomy_default_vocabularies() {
  return array(
    'cmtls_event_keywords' => array(
      'name' => 'Event keywords',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '1',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_cmtls_event_keywords',
      'weight' => '0',
      'nodes' => array(
        'cmtls_event' => 'cmtls_event',
      ),
    ),
  );
}
