<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cmtls_event_content_default_fields() {
  $fields = array();

  // Exported field: field_cmtls_address
  $fields['cmtls_event-field_cmtls_address'] = array(
    'field_name' => 'field_cmtls_address',
    'type_name' => 'cmtls_event',
    'display_settings' => array(
      'weight' => '35',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_cmtls_address][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Location',
      'weight' => '35',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_cmtls_event_date
  $fields['cmtls_event-field_cmtls_event_date'] = array(
    'field_name' => 'field_cmtls_event_date',
    'type_name' => 'cmtls_event',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datetime',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => 'required',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'strtotime',
      'default_value_code' => 'tomorrow',
      'default_value2' => 'strtotime',
      'default_value_code2' => 'tomorrow',
      'input_format' => 'd.m.Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '31',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_cmtls_event_lasts_all_day
  $fields['cmtls_event-field_cmtls_event_lasts_all_day'] = array(
    'field_name' => 'field_cmtls_event_lasts_all_day',
    'type_name' => 'cmtls_event',
    'display_settings' => array(
      'weight' => '8',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Event does not last all day
1|Event lasts all day',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Event lasts all day',
      'weight' => '8',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_cmtls_files
  $fields['cmtls_event-field_cmtls_files'] = array(
    'field_name' => 'field_cmtls_files',
    'type_name' => 'cmtls_event',
    'display_settings' => array(
      'weight' => '6',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => '',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '10M',
      'max_filesize_per_node' => '50M',
      'label' => 'Files',
      'weight' => '6',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_cmtls_geoinfo
  $fields['cmtls_event-field_cmtls_geoinfo'] = array(
    'field_name' => 'field_cmtls_geoinfo',
    'type_name' => 'cmtls_event',
    'display_settings' => array(
      'weight' => '33',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'openlayers_wkt',
    'required' => '0',
    'multiple' => '0',
    'module' => 'openlayers_cck',
    'active' => '1',
    'openlayers_cck_feature_types' => array(
      'point' => 'point',
      'path' => 0,
      'polygon' => 0,
    ),
    'widget' => array(
      'openlayers_cck_preset_map' => 'cmtls_map',
      'openlayers_cck_show_empty_map' => 0,
      'openlayers_cck_zoom_to_layer' => 0,
      'openlayers_cck_zoom_to_layer_level' => '10',
      'keep_points' => 0,
      'default_value' => array(
        '0' => array(
          'openlayers_wkt' => '',
        ),
      ),
      'default_value_php' => NULL,
      'openlayers_behaviors' => array(
        'openlayers_behavior_zoomtolayer' => array(
          'enabled' => 0,
          'options' => array(
            'zoomtolayer' => 'openlayers_cck_vector_layer',
            'point_zoom_level' => '5',
          ),
        ),
      ),
      'autocompletion_field_cmtls_address_enable' => 1,
      'autocompletion_field_cmtls_address_override' => 1,
      'autocompletion_field_cmtls_address_content' => '',
      'autocompletion_field_cmtls_address_type' => 'input',
      'position' => '10',
      'label' => 'Geo info',
      'weight' => '33',
      'description' => '',
      'type' => 'openlayers_geocoder_widget',
      'module' => 'openlayers_geocoder',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Date');
  t('Event lasts all day');
  t('Files');
  t('Geo info');
  t('Location');

  return $fields;
}
