<?php
/**
 * Variables available:
 * 
 * - $href
 * 
 */

?><div id="cmtls-pager" class="hidden">
	<div id="cmtls-pager-loading" class="hidden"><?php print t('Loading').'..'; ?></div>
	<a href="<?php print $href; ?>" id="cmtls-pager-more-button"><?php print t('More items'); ?> (<span id="cmtls-pager-more-items-count"></span>)</a>
</div>