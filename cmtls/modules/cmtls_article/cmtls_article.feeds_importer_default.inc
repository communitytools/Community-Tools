<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function cmtls_article_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cmtls_articles_rss_feed';
  $feeds_importer->config = array(
    'name' => 'Community Tools articles RSS import',
    'description' => 'Community Tools articles RSS import',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'SimplePieGeoWKTParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'cmtls_article',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'parent:og_groups',
            'target' => 'og_groups',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'parent:nodehierarchy',
            'target' => 'parent',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'tags',
            'target' => 'taxonomy:features_cmtls_article_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'url',
            'target' => 'body_append',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'geolocation_wkt',
            'target' => 'field_cmtls_geoinfo',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
      ),
    ),
    'content_type' => 'cmtls_app',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['cmtls_articles_rss_feed'] = $feeds_importer;
  return $export;
}
