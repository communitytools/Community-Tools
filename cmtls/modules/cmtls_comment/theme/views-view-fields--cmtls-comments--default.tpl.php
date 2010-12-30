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

?>
<div class="comment">

	<div class="avatar">
		<?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 40); ?>
	</div>
	
	<div class="comment-content">
		<div class="meta-author">
			<?php print _cmtls_member_name($fields, TRUE); ?>
		</div>
		
		<div class="meta-time">
			<?php print $fields['timestamp']->content; ?>
		</div>
<?php if(cmtls_comment_is_deletable($cmtls['current_group'], $fields['uid']->raw, $fields['timestamp']->raw, $user)): ?>
				<?php print l('', 'cmtls/comment/'.$fields['cid']->raw.'/delete', array('attributes' => array('class' => 'modalframe-child comment-delete comment-delete-button', 'alt' => t('Delete comment'), 'title' => t('Delete comment')))); ?>
			<?php endif; ?>
		<div class="comment-text">
			<?php print $fields['comment']->content; ?>
		</div>
	</div>

</div>

