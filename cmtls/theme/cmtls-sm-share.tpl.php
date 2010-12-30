<?php
/**
 * Variables available: 
 *	
 * $href: object detail view URL
 *  
 */

?>

<script type="text/javascript">
	var addthis_config = {
	
		ui_language: "<?php print $language->language ?>",
		ui_cobrand: "Community Tools",
		ui_click: true,
		services_compact: 'facebook,twitter,linkedin,orkut,tumblr,email,blogger,delicious,digg,menu',
		ui_use_css: false, /* doesn't seem to work? */

	}
</script>

<a href="http://www.addthis.com/bookmark.php" class="addthis_button" addthis:url="<?php print $href; ?>"><?php print t('Share'); ?></a>
&middot;
<a class="addthis_button_facebook_like" fb:like:height="20" fb:like:layout="button_count" addthis:url="<?php print $href; ?>"></a> 

<?php /*  <a class="addthis_button_email"></a> */ ?>