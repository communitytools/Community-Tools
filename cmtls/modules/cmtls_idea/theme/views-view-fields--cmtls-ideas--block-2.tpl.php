<?php
// $Id$
?>

<div class="dashboard-item">
	<?php print l($fields['title']->raw, cmtls_path_to_node($fields['nid']->raw, $cmtls['current_group'])); ?>
	<span class="dashboard-meta">&middot; <?php print $fields['created']->content; ?></span>
</div><!-- dashboard-item -->