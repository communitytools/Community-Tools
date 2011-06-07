<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

?><div class="meta-geo">
	<?php if(($node->field_cmtls_geoinfo['0']['openlayers_wkt'] && $node->field_cmtls_geoinfo['0']['openlayers_wkt'] != 'GEOMETRYCOLLECTION()')): ?>
		<a class="cmtls-map-popup" id="cmtls-map-feature-<?php print $node->nid; ?>"><?php print cmtls_map_get_icon($node->parent); ?></a>
	<?php endif; ?>
</div> <!-- meta-geo -->