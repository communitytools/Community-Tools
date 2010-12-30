<?php

/**
 * Implementation of hook_strongarm().
 */
function cmtls_map_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_default_preset';
  $strongarm->value = 'cmtls_map';

  $export['openlayers_default_preset'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_source';
  $strongarm->value = 'sites/all/libraries/openlayers/OpenLayers.js';

  $export['openlayers_source'] = $strongarm;
  return $export;
}
