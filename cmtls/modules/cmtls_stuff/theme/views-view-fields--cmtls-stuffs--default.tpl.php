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
$title = theme('cmtls_node_title', $node);
$files = theme('cmtls_node_files', $node);

?>

<?php /* Node detail view */ ?>
<?php if (isset($view->args[1])): ?>

	<div class="text-node">

		<div class="node-head">

			<?php print $title; ?>
		
			<?php print $tags; if (trim($tags)) print '&middot'; ?>
			<?php print t('Owner').' '.$author; ?> &middot;
	
			<div class="meta-author">
				<?php // TODO: template for loaned to and until ?>
				<?php if($node->field_cmtls_stuff_loan_uid[0]['value']): ?>
					<?php print t('Loaned until').' '.date_format_date(date_make_date($node->field_cmtls_stuff_loan_date[0]['value']), 'custom', 'j. F Y'); ?>: <?php print _cmtls_member_avatar($user->uid == $node->field_cmtls_stuff_loan_uid[0]['value'] ? $user : $node->field_cmtls_stuff_loan_uid[0]['value'], 16, TRUE); ?> <?php print cmtls_member_name($user->uid == $node->field_cmtls_stuff_loan_uid[0]['value'] ? $user : $node->field_cmtls_stuff_loan_uid[0]['value'], TRUE); ?>
					<?php if(node_access('update', $node)): ?>
						 &middot; <?php print l(t('Mark as returned'), cmtls_path_to_node($node).'/returned', array('attributes' => array('class' => 'cmtls-button'))); ?>
					<?php endif; ?>
				<?php elseif($user->uid != $node->uid): ?>
					<?php if($user->uid): ?>
					<?php print l(t('Request this item'), cmtls_path_to_node($node).'/request', array('attributes' => array('class' => 'modalframe-child cmtls-button'))); ?>
					<?php else: ?>
					    <?php print l(t('Request this item'), 'cmtls/login', array('attributes' => array('class' => 'cmtls-button modalframe-child', 'id' => 'add-node-button'))) ?>
					<?php endif; ?>
				<?php endif; ?>
			</div> <!-- meta-author -->
		
		
		</div> <!-- node-head -->
		
		<div class="node-content">
		
			<?php print check_markup($node->body, $node->format, FALSE); ?>
		
			<?php print $files; ?>
		
			<?php //printr($node); ?>
			
		</div> <!-- node-content -->
		
		<div class="node-footer">
				
		
			<?php print $comment_links; ?>
		
			<?php print $comments; ?>
		
		</div> <!-- node-footer -->
		
	</div> <!-- text-node -->	
	
<?php /* Node list view */ ?>
<?php else: ?>

	<div class="text-node-list-item">
		
		<div class="meta-files">
		<?php foreach ((array)$node->field_cmtls_files as $file): ?>
			<?php if (is_array($file)): ?>
				<div class="meta-file">
					<a href="<?php print $file['imagecache_object_type'] == 'image' ? imagecache_create_url('full', $file['filepath']) : $base_url.'/'.$file['filepath']; ?>" title="<?php print $file['data']['description']; ?>" <?php print ($file['imagecache_object_type'] == 'image' ? 'rel="lightbox[' . $node->nid . ']"' : ''); ?>>
						<?php print $file['imagecache_icon']; ?>
					</a>
				</div>
			<?php break; ?>
			<?php endif; ?>
		<?php endforeach; ?>
		</div> <!-- meta-files -->
		
		<ul>
			<li><h1><?php print(l($node->title, cmtls_path_to_node($node))); ?></h1></li>
			<li><?php print $tags; ?></li>
		</ul>
	</div>

<?php endif; ?>
