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

<div class="profile-left">
	<div class="profile<?php echo (og_is_group_admin($cmtls['current_group'], $user->uid == $fields['uid']->raw ? $user : user_load($fields['uid']->raw)) ? '-admin' : ''); ?>">
		<div class="avatar">
			<?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 55, TRUE); ?>
		</div>
		<ul>
			<li><strong><?php print l(_cmtls_member_name($fields), 'cmtls/'.$cmtls['current_group']->nid.'/member/'.$fields['uid']->raw); ?></strong></li>
			<?php if(og_is_group_admin($cmtls['current_group'], $user->uid == $fields['uid']->raw ? $user : user_load($fields['uid']->raw))): ?><li class="admin-title"><?php print t('Group administrator') ?></li><?php endif; ?>
			<?php if($user->uid): ?>
			<li><?php print $fields['mail']->content ;?></li>
			<?php if($fields['value_2']->raw): ?><li><div class="line-description"><?php print t('Address') ?>:</div> <?php print check_plain($fields['value_2']->raw) ;?></li><?php endif; ?>
			<?php if($fields['value_5']->raw): ?><li><div class="line-description"><?php print t('Phone') ?>:</div> <a href="callto:<?php print check_plain($fields['value_5']->raw) ;?>"><?php print check_plain($fields['value_5']->raw) ;?></a></li><?php endif; ?>
			<?php if($fields['value_1']->raw): ?><li><div class="line-description"><?php print t('Skype') ?>:</div> <a href="skype:<?php print check_plain($fields['value_1']->raw) ;?>"><?php print check_plain($fields['value_1']->raw) ;?></a></li><?php endif; ?>
			<?php /*
			<li><div class="line-description"><?php print t('Description') ?>:</div> <?php print check_plain($fields['value_3']->raw) ;?></li>
			<li><div class="line-description"><?php print t('Homepage') ?>:</div> <?php print $fields['value_4']->content ;?></li>*/ ?>
			<?php endif; ?>
		</ul>
	</div>
</div>
	