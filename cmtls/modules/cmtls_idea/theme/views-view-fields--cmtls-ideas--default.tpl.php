<?php
// $Id$

$node = node_load($fields['nid']->raw);

$current_group = _cmtls_group_get_current();
$current_app = _cmtls_app_get_current($current_group);

?>

<?php /* Node detail view */ ?>
<?php if (isset($view->args[1])): ?>

	<div class="node-head">

		<h1><?php print _cmtls_edit_button($fields['nid']->raw); ?><?php print $fields['title']->raw; ?></h1>

		<div class="meta-author">
			<a href="" class="avatar"><?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 16, TRUE); ?></a>
			<?php print _cmtls_member_name($fields, TRUE).' '.t('wrote').' '; ?>
		</div> <!-- meta-author -->

		<div class="meta-time">
			<?php print $fields['created']->content; ?> &middot;
		</div> <!-- meta-time -->

		<div class="meta-status">
			<?php print t($fields['field_cmtls_idea_status_value']->content); ?>
		</div> <!-- meta-status -->

		<div class="meta-geo">
			<?php if(($fields['field_cmtls_geoinfo_openlayers_wkt']->raw && $fields['field_cmtls_geoinfo_openlayers_wkt']->raw != 'GEOMETRYCOLLECTION()')): ?>
				<a class="cmtls-map-popup" id="cmtls-map-feature-<?php print $fields['nid']->raw; ?>"><?php print cmtls_map_get_icon($view->args[0]); ?></a>
			<?php endif; ?>
		</div> <!-- meta-geo -->
		<div class="meta-address"><?php print $fields['field_cmtls_address_value']->raw; ?></div>

	</div> <!-- node-head -->

	<div class="node-content">

		<?php print $fields['body']->content; ?>

		<div class="meta-files">
			<?php foreach ((array)$node->field_cmtls_files as $file): ?>
				<?php if (is_array($file)): ?>
					<div class="meta-file">
						<a href="<?php print url($file['filepath'], array('absolute' => TRUE)); ?>" title="<?php print $file['data']['description']; ?>" <?php print ($file['imagecache_object_type'] == 'image' ? 'rel="lightbox[' . $node->nid . ']"' : ''); ?>>
							<?php print $file['imagecache_icon']; ?>
						</a>
					</div>
				<?php endif; ?>
			<?php endforeach; ?>
		</div> <!-- meta-files -->

	</div> <!-- node-content -->

	<div class="node-footer">

		<?php if (is_array($node->taxonomy)): ?>
			<?php if (count($node->taxonomy) > 0): ?>
				<div class="meta-tags">
					<?php print t('Tagged').': '; ?>
					<?php foreach ($node->taxonomy as $term): ?>
						<a href="<?php print url('cmtls/' . $current_group->nid . '/' . $current_app->nid, array('absolute' => TRUE)) . '?tag=' .  $term->tid; ?>" class="category"><?php print check_plain($term->name); ?></a><?php if ($i < count($node->taxonomy) - 1) print ', '; $i++; ?>
					<?php endforeach; ?>
				</div> <!-- meta-tags -->
				&middot;
			<?php endif; ?>
		<?php endif; ?>

		<?php print l($fields['comment_count']->raw ? format_plural($fields['comment_count']->raw,'1 comment','@count comments') : t('Comment'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/article/'.$fields['nid']->raw, array('attributes' => array('class' => 'comments-button cmtls-comment-toggle-button', 'id' => 'cmtls-comments-toggle-button-'.$fields['nid']->raw))); ?>

		&middot; <a class="stance-button" href=""><?php print $node->stances->sorted_count[1] + $node->stances->sorted_count[2] ? $node->stances->sorted_count[1] . ' ' . t('for') . ' / ' . $node->stances->sorted_count[2] . ' ' . t('against') :  t('Vote'); ?></a>

		&middot; <div class="meta-share"><?php print $sm_share_buttons; ?></div>

		<?php print $stance; ?>

		<?php print $comments; ?>

	</div> <!-- node-footer -->

<?php /* Node list view */ ?>
<?php else: ?>

	<div class="text-node-list-item">

		<h1><?php print _cmtls_edit_button($fields['nid']->raw); ?><a href="<?php print base_path().cmtls_idea_path($node); ?>"><?php print $fields['title']->raw; ?></a></h1>

		<?php if (is_array($node->taxonomy)): ?>
			<?php if (count($node->taxonomy) > 0): ?>
				<div class="meta-tags">
					<?php /* print t('Tagged').': '; */ ?>
					<?php foreach ($node->taxonomy as $term): ?>
						<a href="<?php print url('cmtls/' . $current_group->nid . '/' . $current_app->nid, array('absolute' => TRUE)) . '?tag=' . $term->tid; ?>" class="category"><?php print check_plain($term->name); ?></a><?php if ($i < count($node->taxonomy) - 1) print ', '; $i++; ?>
					<?php endforeach; ?>
				</div> <!-- meta-tags -->
				&middot;
			<?php endif; ?>
		<?php endif; ?>

		<div class="meta-geo">
			<?php if(($fields['field_cmtls_geoinfo_openlayers_wkt']->raw && $fields['field_cmtls_geoinfo_openlayers_wkt']->raw != 'GEOMETRYCOLLECTION()')): ?>
				<a class="cmtls-map-popup" id="cmtls-map-feature-<?php print $fields['nid']->raw; ?>"><?php print cmtls_map_get_icon($view->args[0]); ?></a>
			<?php endif; ?>
		</div> <!-- meta-geo -->

		<div class="meta-time">
			<?php print $fields['comment_count']->raw ? format_plural($fields['comment_count']->raw,'1 comment','@count comments') : ''; ?>
			<?php print $node->stances->sorted_count[1] + $node->stances->sorted_count[2] ? ' &middot; ' .$node->stances->sorted_count[1] . ' ' . t('for') . ' / ' . $node->stances->sorted_count[2] . ' ' . t('against') :  ''; ?>
		</div>

		<?php print node_teaser($fields['body']->content, NULL, 200); ?><?php print node_teaser($fields['body']->content, NULL, 200) < $fields['body']->content ? '..' : NULL; ?>

		 &middot; <a href="<?php print base_path().cmtls_idea_path($node); ?>" title="<?php print t('Read more'); ?>"><?php print t('Read more'); ?></a>

        </div>

<?php endif; ?>



