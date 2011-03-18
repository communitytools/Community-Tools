<?php

/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile.
 */
function cmtls_profile_details()
{
	return array(
		'name' => 'Community Tools',
		'description' => 'Tools for creating and managing communities.',
	);
}

/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * @return
 *  An array of modules to be enabled.
 */
function cmtls_profile_modules()
{
	return array(
		// Enable required core modules first.
		'system',
		'block',
		'filter',
		'node',
		'user',

		// Enable optional core modules next.
		'comment',
		'dblog', 
		'help',
		'menu',
		'openid',
		'path',
		'profile',
		'search',
		'taxonomy',
		'trigger',
		'upload',
		'locale',

		// Then,enable any contributed modules here.
		'install_profile_api',
		'jquery_update',
		'jquery_ui',
		'jquery_ui_dialog',
		'sections',
		'onepageprofile',
		'modalframe',
		'jlightbox',


		// views
		'views',
		'views_export',
		'views_ui',

		// Tools to build content types.
		'date_api',
		'date_timezone',
		'content',
		'content_copy',
		'content_permissions',
		'optionwidgets',
		'filefield',
		'fieldgroup',
		'imagefield',
		'number',
		'text',
		'imageapi',
		'imagecache',
		'imagecache_ui',
		'imageapi_gd',
		'date',
		'date_popup',

		// Organic Groups
		'og',
		'og_access',
		'og_actions',
		'og_views',

		// WYSIWYG
		'wysiwyg',
		'wysiwyg_imageupload',

		// Outgoing communications.
		'googleanalytics',

		// Node hierarchy
		'nodehierarchy',
		'nodehierarchy_views',


		// Misc.
		'token',
		
		// CAPTCHA
		'captcha',
		'image_captcha',
		
		// Feeds
		'feeds',
		'job_scheduler'

		// Things general user never sees.
		//'admin_menu',
	);
}

/*
 * Install some modules later to avoid installation hangs.
 */
function _cmtls_additional_modules()
{
	return array(
		// Tools that glue the site together after install.
		'ctools',
		'features',
		'strongarm',

		// modules that require db before install
		'activity',

		// modules that require ctools
		// Openlayers
		'openlayers',
		'openlayers_ui',
		'openlayers_cck',
		'openlayers_filters',
		'openlayers_geocoder',

		// cmtls core
		'cmtls',
		'cmtls_map',
		'cmtls_group',
		'cmtls_app',
		'cmtls_auth',
		'cmtls_fb',
		'cmtls_openid',
		'cmtls_upload',
		'cmtls_member',
		'cmtls_comment',
		'cmtls_stance',
		'cmtls_filter',
		'cmtls_feed',

		// cmtls apps
		'cmtls_dashboard',
		'cmtls_article',
		'cmtls_event',
		'cmtls_forum',
		'cmtls_gallery',
		'cmtls_idea',
		'cmtls_problem',
		'cmtls_place',
	);
}

/**
 * Implementation of hook_profile_tasks().
 *
 * (State machine modelled after Atrium installer.)
 */
function cmtls_profile_tasks(&$task, $url)
{
	global $profile, $install_locale;

	$output = "";

	require_once('profiles/default/default.profile');

	if ($task == 'profile')
	{

		// Install the base module set.
		install_include(cmtls_profile_modules());

		// Enable much of the architecture via features.
		$modules =  _cmtls_additional_modules();
		foreach ($modules as $module)
		{
			_drupal_install_module($module);
			module_enable(array($module));  
		}

		/*
		watchdog('cmtls', 'setting up terms & menu');
		// Add some categories to the Sections vocabulary. (Once the Sections vocabulary has been created by a feature.)
		$vid = install_taxonomy_get_vid('Section');
		install_taxonomy_add_term($vid, 'Business');
		install_taxonomy_add_term($vid, 'Arts');
		install_taxonomy_add_term($vid, 'Non-profit');
		install_taxonomy_add_term($vid, 'Gardening');
		install_taxonomy_add_term($vid, 'General site info');
		install_taxonomy_add_term($vid, 'News');
		install_taxonomy_add_term($vid, 'Public services');
		install_taxonomy_add_term($vid, 'Recreation');
		install_taxonomy_add_term($vid, 'Transportation');
		*/

		// add the default page and story node types
		// Insert default user-defined node types into the database. For a complete
		// list of available node type attributes, refer to the node type API
		// documentation at: http://api.drupal.org/api/HEAD/function/hook_node_info.
		$types = array(
			array(
				'type' => 'page',
				'name' => st('Page'),
				'module' => 'node',
				'description' => st("A <em>page</em>, similar in form to a <em>story</em>, is a simple method for creating and displaying information that rarely changes, such as an \"About us\" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site's initial home page."),
				'custom' => TRUE,
				'modified' => TRUE,
				'locked' => FALSE,
				'help' => '',
				'min_word_count' => '',
			),
			array(
				'type' => 'story',
				'name' => st('Story'),
				'module' => 'node',
				'description' => st("A <em>story</em>, similar in form to a <em>page</em>, is ideal for creating and displaying content that informs or engages website visitors. Press releases, site announcements, and informal blog-like entries may all be created with a <em>story</em> entry. By default, a <em>story</em> entry is automatically featured on the site's initial home page, and provides the ability to post comments."),
				'custom' => TRUE,
				'modified' => TRUE,
				'locked' => FALSE,
				'help' => '',
				'min_word_count' => '',
			),
		);

		foreach ($types as $type)
		{
			$type = (object) _node_type_set_defaults($type);
			node_type_save($type);
		}

		// Default date popup styles (this is the actual default, but there seems to be some error with it)
		variable_set('node_options_page', 'sites/all/modules/date/date_popup/themes/datepcker.1.7.css');
		
		// Default page to not be promoted and have comments disabled.
		variable_set('node_options_page', array('status'));
		variable_set('comment_page', COMMENT_NODE_DISABLED);

		// Don't display date and author information for page nodes by default.
		$theme_settings = variable_get('theme_settings', array());
		$theme_settings['toggle_node_info_page'] = FALSE;
		variable_set('theme_settings', $theme_settings);

		// ccs, js compression
		variable_set('preprocess_css', 1);
		variable_set('preprocess_js', 1);

		// normal cache
		variable_set('cache', 1);

		// no page compression
		variable_set('page_compression', 0);

		// Hand control back to installer.
		module_rebuild_cache();

		drupal_flush_all_caches();

		features_rebuild();

		node_access_rebuild(TRUE);
		variable_del('node_access_needs_rebuild');

		variable_set('site_frontpage', 'cmtls');
		
		variable_set('openlayers_source', 'sites/all/libraries/openlayers/OpenLayers.js');

		system_theme_data();

		// themes and blocks
		// enable garland and cmtls_theme
		db_query("UPDATE system SET status = 1 WHERE name = 'garland'");
		db_query("UPDATE system SET status = 1 WHERE name = 'cmtls_theme'");

		// clear cmtls_theme blocks
		db_query("UPDATE {blocks} SET region = NULL, status = 0 WHERE theme = 'cmtls_theme'");

		// add cmtls theme site menu
		db_query("INSERT INTO blocks (module, delta, theme, status, region) VALUES ('cmtls', 'cmtls_site_menu', 'cmtls_theme', 1, 'cmtls_site_menu')");

		$task = 'profile-finished';

		// disable og, nodehierarchy views
		$status = variable_get('views_defaults', array());

		$status['nodehierarchy_children_teasers'] = TRUE;
		$status['nodehierarchy_children_list'] = TRUE;

		$status['og'] = TRUE;
		$status['og_files'] = TRUE;
		$status['og_ghp_ron'] = TRUE;
		$status['og_members'] = TRUE;
		$status['og_members_block'] = TRUE;
		$status['og_members_faces'] = TRUE;
		$status['og_my'] = TRUE;
		$status['og_mytracker'] = TRUE;
		$status['og_recent_type_term'] = TRUE;
		$status['og_search'] = TRUE;
		$status['og_tracker'] = TRUE;
		$status['og_unread'] = TRUE;

		variable_set('views_defaults', $status);

		menu_rebuild();

		// add the main group node
		db_query("INSERT INTO {content_field_cmtls_address} VALUES (1, 1, NULL)");
		db_query("INSERT INTO {content_field_cmtls_geoinfo} VALUES (1, 1, NULL)");
		db_query("INSERT INTO {content_type_cmtls_group} VALUES (1, 1, NULL, NULL, NULL, 1, 0)");
		db_query("INSERT INTO {node} VALUES (1, 1, 'cmtls_group', 'en', 'Main group', 1, 1, NOW(), NOW(), 0, 0, 0, 0, 0, 0)");
		db_query("INSERT INTO {node_access} VALUES (1, 1, 'og_admin', 1, 1, 0)");
		db_query("INSERT INTO {node_access} VALUES (1, 0, 'og_public', 1, 0, 0)");
		db_query("INSERT INTO {node_comment_statistics} VALUES (1, NOW(), NULL, 1, 0)");
		db_query("INSERT INTO {node_revisions} VALUES (1, 1, 1, 'Main group', '', '', '', NOW(), 2)");
		db_query("INSERT INTO {nodehierarchy} VALUES (1, 0, 0)");
		db_query("INSERT INTO {og} VALUES (1, 0, 'Main group', '', 0, 0, '', 0)");
		db_query("INSERT INTO {og_uid} VALUES (1, 0, 1, 1, 1, NOW(), NOW())");
		
	    file_create_path(variable_get('user_picture_path', 'pictures'));
	}
	return $output;
}

// Set cmtls as default profile.
// (from Atrium installer: This is a trick for hooks to get called,otherwise we cannot alter forms.)
function system_form_install_select_profile_form_alter(&$form, $form_state)
{
	foreach ($form['profile'] as $key => $element)
	{
		$form['profile'][$key]['#value'] = 'cmtls';
	}
}
