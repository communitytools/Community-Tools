<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

?><div class="meta-author">
	<?php print _cmtls_member_avatar($user->uid == $node->uid ? $user : $node->uid, 16, TRUE); ?> <?php print cmtls_member_name($user->uid == $node->uid ? $user : $node->uid, TRUE); ?>
</div>