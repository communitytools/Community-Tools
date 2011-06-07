<?php

/**
 * Implementation of hook_ckeditor_profile_defaults().
 */
function cmtls_ckeditor_profile_defaults() {
  $data = array(
    'Advanced' => array(
      'name' => 'Advanced',
      'settings' => array(
        'allow_user_conf' => 'f',
        'filters' => array(
          'filter/3' => 1,
          'filter/0' => 1,
          'openlayers_filters/0' => 0,
        ),
        'ss' => '2',
        'min_rows' => '1',
        'excl_mode' => '0',
        'excl' => '',
        'simple_incl' => '',
        'default' => 't',
        'show_toggle' => 'f',
        'popup' => 'f',
        'skin' => 'kama',
        'uicolor' => 'default',
        'uicolor_textarea' => '<p>
	Click on the <strong>UI Color Picker</strong> button to set your color preferences.</p>
',
        'uicolor_user' => 'default',
        'toolbar' => 'DrupalFiltered',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'imce',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => '0',
        'forcePasteAsPlainText' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'excl_regex' => '',
        'simple_incl_regex' => '',
      ),
      'roles' => array(
        'authenticated user' => 'authenticated user',
        'admin' => 'admin',
      ),
    ),
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'rank' => array(
          '0' => '3',
          '1' => '2',
        ),
        'excl_mode' => '1',
        'excl' => '*@cmtls/*/edit.edit-body
cmtls/*/add.edit-body
*@node/add/*.edit-body
*@node/*/edit.edit-body
',
        'simple_incl' => '*.edit-signature
admin/settings/site-information.*
admin/settings/site-maintenance.*
*.edit-page-help
*.edit-user-registration-help
*.edit-user-picture-guidelines
',
        'ckeditor_path' => '%m/ckeditor',
        'ckeditor_local_path' => '',
        'show_fieldnamehint' => 't',
        'excl_regex' => '#(?:^.*@cmtls/.*/edit\\.edit-body$)|(?:^.*@cmtls/.*/add\\.edit-body$)|(?:^.*@node/add/.*\\.edit-body$)|(?:^.*@node/.*/edit\\.edit-body$)#',
        'simple_incl_regex' => '#(?:^.*@.*\\.edit-signature$)|(?:^.*@admin/settings/site-information\\..*$)|(?:^.*@admin/settings/site-maintenance\\..*$)|(?:^.*@.*\\.edit-page-help$)|(?:^.*@.*\\.edit-user-registration-help$)|(?:^.*@.*\\.edit-user-picture-guidelines$)#',
      ),
      'roles' => array(),
    ),
    'Default' => array(
      'name' => 'Default',
      'settings' => array(
        'allow_user_conf' => 'f',
        'min_rows' => 1,
        'excl_mode' => 0,
        'filebrowser' => 'none',
        'quickupload' => 'f',
        'excl' => '',
        'simple_incl' => '',
        'ss' => '2',
        'filters' => array(
          'filter/0' => 1,
        ),
        'default' => 't',
        'show_toggle' => 't',
        'popup' => 'f',
        'skin' => 'kama',
        'toolbar' => 'DrupalBasic',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'format_source' => 't',
        'format_output' => 't',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'user_choose' => 'f',
        'show_fieldnamehint' => 't',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => 0,
        'scayt_autoStartup' => 'f',
        'excl_regex' => '',
        'simple_incl_regex' => '',
      ),
      'roles' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  return $data;
}
