<div class="gallery-item">
	<?php /* if($fields['field_cmtls_address_value']->raw): ?>
	<div class="gallery-item-geotag">
		<div class="help-text">
			<?php print $fields['field_cmtls_address_value']->raw ?>
			<a href="#näita kaardil"><?php print t('All photos from that location') ?></a>
		</div>
	</div>
	<?php endif */ ?>
	
	<div class="gallery-item-icon">
		<?php print l(!empty($fields['field_cmtls_album_cover_image']->filename) ? theme('imagecache','thumbnail',$fields['field_cmtls_album_cover_image']->filename,$fields['title']->raw,$field['field_cmtls_description']->raw) : '<img src="'.base_path().drupal_get_path('module', 'cmtls_gallery').'/icons/folder.png">' ,'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/album/'.$fields['nid']->raw,array('html'=>true)) ?>
	</div>
	<div class="gallery-item-caption">
		<?php print _cmtls_edit_button($fields['nid']->raw); ?> <?php print l($fields['title']->raw,'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/album/'.$fields['nid']->raw) ?> <?php if($album_object_count): ?><span class="count"><?php print $album_object_count ?></span><?php endif ?>
	</div>
</div>