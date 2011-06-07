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

$node = node_load($fields['nid']->raw);

$tags = theme('cmtls_node_tags', $node);
$author = theme('cmtls_node_author', $node);
$comment_links = theme('cmtls_node_comment_links', $node);
$created = theme('cmtls_node_created_time', $node);
$geolocation = theme('cmtls_node_geolocation', $node);
$title = theme('cmtls_event_node_title', $node);
$files = theme('cmtls_node_files', $node);
$detail_view = theme('cmtls_node_detail_view_link', $node);

?><?php /* Node detail view */ ?>
<?php if (isset($view->args[1])): ?>

	<?php print $title; ?>
	
	<div class="node-head">

		<?php print $author; ?>

		<?php print $created; ?>

		<?php print $geolocation; ?>

	</div>

	<div class="node-content">

		<?php print check_markup($node->body, $node->format, FALSE); ?>

		<?php print $files; ?>

	</div> <!-- node-content -->

	<div class="node-footer">

		<?php print $tags; if (trim($tags)) print '&middot;'; ?>

		<?php print $comment_links; ?>

		&middot;

		<?php print l(($node->stances->sorted_count[1] > 0 ? format_plural($node->stances->sorted_count[1],'1 attending','@count attending') : t('Attend')), '', array('attributes' => array('class' => 'stance-button', 'rel' => '#stance-container-'.$node->nid))); ?>

		&middot;
		
		<?php print l(t('Add to calendar'), cmtls_path_to_node($node).'/add_to_calendar.ics'); ?>
		
		<?php if(node_access('update', $node, $user)): ?>
			&middot;
			<?php print l(t('Send e-mail to participants'), cmtls_path_to_node($node).'/send_mail', array('attributes' => array('class' => 'modalframe-child'))); ?> 
		<?php endif; ?>

		&middot; <?php print $sm_share_buttons; ?>

		<?php print $stance; ?>
		<?php print $comments; ?>

	</div>

<?php /* Node list view */ ?>
<?php else: ?>

	<div class="text-node-list-item">

		<?php print $title; ?>
		
		<?php print $tags; if (trim($tags)) print '&middot;'; ?>
		
		<?php print $geolocation; ?>
		
		<?php print $comment_links; ?>
		
		<div class="meta-time">
			<?php print $node->stances->sorted_count[1] > 0 ? format_plural($node->stances->sorted_count[1],'1 attending','@count attending') : ''; ?>
		</div>

		<?php print node_teaser($node->body, NULL, 200); ?><?php print strlen(node_teaser($node->body, NULL, 200)) < strlen($node->body) ? '..' : NULL; ?>

		<?php ($node->body) ? print ' &middot; ' : NULL; ?>

		<?php print $detail_view ?>
		
		<?php print $comments; ?>
		
	</div> <!-- /text-node-list-item -->

<?php endif; ?>