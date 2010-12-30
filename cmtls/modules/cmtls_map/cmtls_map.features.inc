<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cmtls_map_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
	if ($module == 'openlayers')
	{
		switch ($api)
		{
			case 'openlayers_presets':
				return array('version' => 1);
			
			case 'openlayers_layers':
				return array('version' => 1);
			
			case 'openlayers_styles':
				return array('version' => 1);
		}
	}
}
