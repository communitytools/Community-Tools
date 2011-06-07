<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

$location = theme('cmtls_node_location', $node);

?><h1><?php print _cmtls_edit_button($node); ?><?php print l($node->title, cmtls_path_to_node($node)); ?>
	<span class="date">	&middot; <?php print cmtls_event_date_format($node); ?>
		<?php if($node->field_cmtls_address[0]['value']) print ' &middot; '.check_plain($node->field_cmtls_address[0]['value']); ?>
	</span>
</h1>