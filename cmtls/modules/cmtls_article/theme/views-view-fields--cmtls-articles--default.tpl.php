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
 * - $comments: comments HTML
 *
 * @ingroup views_templates
 */

$node = node_load($fields['nid']->raw);

$tags = theme('cmtls_node_tags', $node);
$author = theme('cmtls_node_author', $node);
$comment_links = theme('cmtls_node_comment_links', $node);
$created = theme('cmtls_node_created_time', $node);
$geolocation = theme('cmtls_node_geolocation', $node);
$location = theme('cmtls_node_location', $node);
$title = theme('cmtls_node_title', $node);
$files = theme('cmtls_node_files', $node);

$teaser = node_teaser($node->body, NULL, 500);

?><div class="node-head">

	<?php print $title; ?>
	
	<?php print $author; ?>
	
	<?php print $created; ?>

	<?php print $geolocation; ?>
	
	<?php print $location; ?>

</div> <!-- node-head -->

<div class="node-content">

	<?php if (isset($view->args[1])): ?>
	
		<?php print check_markup($node->body, $node->format, FALSE); ?>
	
		<?php print $files; ?>
		
	<?php else: ?>

		<div class="node-teaser" data-nid="<?php print $node->nid; ?>">
		
			<?php print $teaser; ?>
			
			<?php if(strlen($teaser) < strlen($node->body) || trim($files)): ?>

				<?/* php print (strlen($teaser) > 0) ? '.. ': NULL ; */?> 
				<?php print l(t('Read more'), cmtls_path_to_node($node), array('attributes' => array('class' => 'node-teaser-to-full', 'data-nid' => $node->nid))); ?>
			
			<?php endif; ?>
			
		</div>			
	
		<div class="node-full hidden" data-nid="<?php print $node->nid; ?>">
		
			<?php print check_markup($node->body, $node->format, FALSE); ?>
			
			<?php print $files; ?>
			
			<?php /*print l(t('See less'), 'cmtls/'.$current_group->nid.'/'.$current_app->nid, array('attributes' => array('class' => 'node-full-to-teaser', 'data-nid' => $node->nid))); */ ?>
		</div>
	
	<?php endif; ?>

</div> <!-- node-content -->

<div class="node-footer">
		
	<?php print $tags; if (trim($tags)) print '&middot;'; ?>

	<?php print $comment_links; ?>

	&middot; <?php print $sm_share_buttons; ?>

	<?php print $comments; ?>

</div> <!-- node-footer -->
