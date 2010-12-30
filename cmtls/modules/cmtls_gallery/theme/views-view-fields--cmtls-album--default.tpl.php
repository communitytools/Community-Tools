<?php

//printr($album_object);

?>

<div class="object-container">
	<?php /* if($fields['field_cmtls_address_value']->raw): ?>
	<div class="object-geotag">
		<div class="help-text">
			<?php print $fields['field_cmtls_address_value']->raw ?>
			<?php print l(t('All photos from that location'),'#näita kaardil') ?>
		</div>
	</div>
	<?php endif */ ?>
	<div class="object-icon">
		<?php print $album_object->icon ?>
	</div>
	
	<div class="object-caption">
		<?php print _cmtls_edit_button($fields['nid']->raw); ?> <?php print $album_object->caption ?>
	</div>
</div>	
