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

<div class="author">
	<?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 16, TRUE); ?> <?php print _cmtls_member_name($fields, TRUE); ?>
</div>

<?php print t('started a thread') ?> 

<?php print l($fields['title']->raw, cmtls_path_to_node($fields['nid']->raw, $cmtls['current_group'])); ?>
<div class="date">
	<?php print $fields['created']->content; ?>
</div>
