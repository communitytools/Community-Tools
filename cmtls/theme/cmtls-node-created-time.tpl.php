<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

?><div class="meta-time">
	<?php print ' '.t('wrote').' '; ?><?php print cmtls_format_date_ago($node->created); ?>
</div>