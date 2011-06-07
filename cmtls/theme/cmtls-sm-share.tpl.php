<?php
/**
 * Variables available: 
 *	
 * $href: object detail view URL
 *  
 */

?><div class="meta-share">
	<a href="http://www.addthis.com/bookmark.php" class="addthis_button" addthis:url="<?php print $href; ?>"><?php print t('Share'); ?></a>
	&middot;
	<a class="addthis_button_facebook_like" fb:like:height="20" fb:like:layout="button_count" addthis:url="<?php print $href; ?>"></a> 
</div>
<?php /*  <a class="addthis_button_email"></a> */ ?>