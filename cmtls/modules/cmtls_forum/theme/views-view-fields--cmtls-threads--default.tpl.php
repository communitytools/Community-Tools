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

<li>
	<?php /* <div class="forum-pin">
		<a href="" class=""></a>
	</div>
	*/ ?>
	<h2><?php print l($fields['title']->raw, _cmtls_app_get_path().'/forum/'.$cmtls['current_forum']->nid.'/'.$fields['nid']->raw); ?><?php print _cmtls_edit_button($fields['nid']->raw); ?></h2>
	<div class="forum-discussions-meta">
		<?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 16, TRUE); ?></a> <?php print _cmtls_member_name($fields, TRUE); ?> <div class="date"><?php print $fields['created']->content ?></div> &mdash; <?php print t('Last reply') ?>: <?php print $fields['last_comment_timestamp']->content; ?> <?php /* <a href="" class="category">Mingi tooli�lene kategooria tag</a> */ ?>
	</div>
	<?php /*
	<div class="address">
		<a class="address-text" href="">Real Strasse</a>
	</div>
	*/ ?>
</li>