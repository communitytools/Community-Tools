<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

$current_year = date('Y');

$start_timestamp = strtotime($fields['field_cmtls_event_date_value']->raw);
$start_year = date('Y', $start_timestamp);
$start_date = date('d.m', $start_timestamp) . ($current_year != $start_year ? '.' . $start_year : '');
$start_time = date('H:i', $start_timestamp);

$end_timestamp = strtotime($fields['field_cmtls_event_date_value2']->raw);
$end_year = date('Y', $end_timestamp);
$end_date = date('d.m', $end_timestamp).($current_year != $end_year ? '.' . $end_year : '');
$end_time = date('H:i', $end_timestamp);

$node = node_load($fields['nid']->raw);

$current_group = _cmtls_group_get_current();
$current_app = _cmtls_app_get_current($current_group);

?>

<?php /* Node detail view */ ?>
<?php if (isset($view->args[1])): ?>


		<h1><?php print _cmtls_edit_button($fields['nid']->raw); ?><?php print check_plain($fields['title']->raw); ?>

			<span class="date">
				&middot;
			<?php if ($fields['field_cmtls_event_lasts_all_day_value']->raw): ?>
				<?php print t('Whole day'); ?>
			<?php else: ?>
				<?php print $start_time; ?> -

				<?php if($start_date != $end_date): ?>
					<?php print $end_date; ?>
				<?php endif; ?>

				<?php if ($end_time != $start_time): ?>
					<?php print $end_time; ?>
				<?php endif; ?>

			<?php endif; ?>

			<?php if($fields['field_cmtls_address_value']->raw) print ' &middot; '.check_plain($fields['field_cmtls_address_value']->raw); ?>

			</span>
		</h1>
	<div class="node-head">

		<div class="meta-author">
			<?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 16, TRUE); ?></a> <?php print _cmtls_member_name($fields, TRUE); ?>
		</div> <!-- meta-author -->

		<div class="meta-time">
			<?php print ' '.t('wrote').' '; ?><?php print $fields['created']->content; ?>
		</div>

		<div class="meta-geo">
			<?php if(($fields['field_cmtls_geoinfo_openlayers_wkt']->raw && $fields['field_cmtls_geoinfo_openlayers_wkt']->raw != 'GEOMETRYCOLLECTION()')): ?>
				<a class="cmtls-map-popup" id="cmtls-map-feature-<?php print $fields['nid']->raw; ?>"><?php print cmtls_map_get_icon($view->args[0]); ?></a>
			<?php endif; ?>
		</div> <!-- meta-geo -->

	</div>

	<div class="node-content">

		<?php print $fields['body']->content; ?>

		<div class="meta-files">
			<?php foreach ((array)$node->field_cmtls_files as $file): ?>
				<?php if (is_array($file)): ?>
					<div class="meta-file">
						<a href="<?php print url($file['imagecache_object_type'] == 'image' ? imagecache_create_url('full', $file['filepath']) : $file['filepath'], array('absolute' => TRUE)); ?>" title="<?php print $file['data']['description']; ?>" <?php print ($file['imagecache_object_type'] == 'image' ? 'rel="lightbox[' . $node->nid . ']"' : ''); ?>>
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
						<a href="<?php print url('cmtls/' . $current_group->nid . '/' . $current_app->nid, array('absolute' => TRUE)) . '?tag=' . $term->tid; ?>" class="category"><?php print check_plain($term->name); ?></a><?php if ($i < count($node->taxonomy) - 1) print ', '; $i++; ?>
					<?php endforeach; ?>
				</div> <!-- meta-tags -->
				&middot;
			<?php endif; ?>
		<?php endif; ?>

		<?php print l($fields['comment_count']->raw ? format_plural($fields['comment_count']->raw,'1 comment','@count comments') : t('Comment'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/article/'.$fields['nid']->raw, array('attributes' => array('class' => 'comments-button cmtls-comment-toggle-button', 'id' => 'cmtls-comments-toggle-button-'.$fields['nid']->raw))); ?>
		&middot;

		<a class="stance-button" href=""><?php print ($node->stances->sorted_count[1] > 0 ? format_plural($node->stances->sorted_count[1],'1 attending','@count attending') : t('Attend')); ?></a>

		&middot;
		<a href="<?php print url('cmtls/' . $current_group->nid . '/' . $current_app->nid . '/event/' . $node->nid . '/add_to_calendar.ics', array('absolute' => TRUE)); ?>"><?php print t('Add to calendar'); ?></a>

		&middot; <div class="meta-share"><?php print $sm_share_buttons; ?></div>

		<?php print $stance; ?>
		<?php print $comments; ?>

	</div>

<?php /* Node list view */ ?>
<?php else: ?>

	<div class="text-node-list-item">

		<h1><?php print _cmtls_edit_button($fields['nid']->raw); ?><a href="<?php print base_path().cmtls_event_path($node); ?>"><?php print check_plain($fields['title']->raw); ?>

			<span class="date">
				&middot; 
			<?php if ($fields['field_cmtls_event_lasts_all_day_value']->raw): ?>
				<?php print t('Whole day'); ?>
			<?php else: ?>
				<?php print $start_time; ?> -

				<?php if($start_date != $end_date): ?>
					<?php print $end_date; ?>
				<?php endif; ?>

				<?php if ($end_time != $start_time): ?>
					<?php print $end_time; ?>
				<?php endif; ?>

			<?php endif; ?>

			<?php if($fields['field_cmtls_address_value']->raw) print ' &middot; '.check_plain($fields['field_cmtls_address_value']->raw); ?>

			</span>
		</a></h1>

		<?php if (is_array($node->taxonomy)): ?>
			<?php if (count($node->taxonomy) > 0): ?>
				<div class="meta-tags">
					<?php /* print t('Tagged').': '; */ ?>
					<?php foreach ($node->taxonomy as $term): ?>
						<a href="<?php print url('cmtls/' . $current_group->nid . '/' . $current_app->nid, array('absolute' => TRUE)) . '?tag=' . $term->tid; ?>" class="category"><?php print check_plain($term->name); ?></a><?php if ($i < count($node->taxonomy) - 1) print ', '; $i++; ?>
					<?php endforeach; ?>
				</div> <!-- meta-tags -->
				<?php ($fields['comment_count']->raw || $node->stances->sorted_count[1] > 0) ? print ' &middot; ' : NULL; ?>
			<?php endif; ?>
		<?php endif; ?>

		<div class="meta-geo">
			<?php if(($fields['field_cmtls_geoinfo_openlayers_wkt']->raw && $fields['field_cmtls_geoinfo_openlayers_wkt']->raw != 'GEOMETRYCOLLECTION()')): ?>
				<a class="cmtls-map-popup" id="cmtls-map-feature-<?php print $fields['nid']->raw; ?>"><?php print cmtls_map_get_icon($view->args[0]); ?></a>
			<?php endif; ?>
		</div> <!-- meta-geo -->

		<div class="meta-time">
			<?php print $fields['comment_count']->raw ? format_plural($fields['comment_count']->raw,'1 comment','@count comments').' &middot; ' : ''; ?>
			<?php print $node->stances->sorted_count[1] > 0 ? format_plural($node->stances->sorted_count[1],'1 attending','@count attending') : ''; ?>
		</div>

		<?php print node_teaser($fields['body']->content, NULL, 200); ?><?php print node_teaser($fields['body']->content, NULL, 200) < $fields['body']->content ? '..' : NULL; ?>

		<?php ($fields['body']->content) ? print ' &middot; ' : NULL; ?>

		 <a href="<?php print base_path().cmtls_event_path($node); ?>" title="<?php print t('Read more'); ?>"><?php print t('Read more'); ?></a>

        </div> <!-- /text-node-list-item -->

<?php endif; ?>