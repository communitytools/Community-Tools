<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

if(sizeof($node->field_cmtls_files) && isset($node->field_cmtls_files[0]) && is_array($node->field_cmtls_files[0])) {
?><div class="meta-files">
	<?php foreach ((array)$node->field_cmtls_files as $file): ?>
		<?php if (is_array($file)): ?>
			<div class="meta-file">
				<a href="<?php print $file['imagecache_object_type'] == 'image' ? imagecache_create_url('full', $file['filepath']) : $base_url.'/'.$file['filepath']; ?>" title="<?php print $file['data']['description']; ?>" <?php print ($file['imagecache_object_type'] == 'image' ? 'rel="lightbox[' . $node->nid . ']"' : ''); ?>>
					<?php print $file['imagecache_icon']; ?>
				</a>
			</div>
		<?php endif; ?>
	<?php endforeach; ?>
</div> <!-- meta-files --><?php }