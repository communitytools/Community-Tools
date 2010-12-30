<?php
// $Id$
?>

<div class="author">
	<?php print _cmtls_member_avatar($user->uid == $fields['uid']->raw ? $user : $fields['uid']->raw, 16, TRUE); ?></a>
	<?php print _cmtls_member_name($fields, TRUE); ?>
</div>

<?php print t('wrote') ?>

<?php print l($fields['title']->raw, cmtls_path_to_node($fields['nid']->raw, $cmtls['current_group'])); ?>
<div class="date">
	<?php print $fields['created']->content; ?>
</div>
