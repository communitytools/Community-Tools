<?php
/**
 * Variables available:
 * - $node_id: node ID
 * - $load_comments_with_ajax
 * 
 */

$vars = array(
	'cmtls' => array(
		'comments' => array(
			'loadCommentsWithAjax' => $load_comments_with_ajax,
		),
	),
);

drupal_add_js($vars, 'setting');

$node = node_load($node_id);

?><div class="comments-container<?php print ($load_comments_with_ajax ? ' hidden' : ''); ?>" id="comments-container-<?php print $node_id; ?>">

	<div id="cmtls-comments-loading-<?php print $node_id; ?>"<?php print (!$load_comments_with_ajax || ($node->comment_count == 0) ? ' class="hidden"' : ''); ?>>
		<?php print t('Loading ...'); ?>
	</div>
	
	<div id="cmtls-comments-<?php print $node_id; ?>">
		<?php if(!$load_comments_with_ajax) print views_embed_view('cmtls_comments', 'default', $node_id); ?>
	</div>
	
	<?php if($user->uid): ?>
	    <div class="comment">
	            <div class="avatar"><?php print _cmtls_member_avatar($user, 40); ?></div>
	            <div class="comment-form" id="cmtls-comment-form-<?php print $node_id; ?>"><?php print drupal_get_form('comment_form', array('nid' => $node_id)); ?></div>
	    </div>
	<?php endif; ?>
	
	<?php if(!$user->uid): ?>
		<div class="comment">
			<?php print t('Please <a href="@href" class="@class">log in</a> to leave a comment.', array('@href' => $base_url.'cmtls/login', '@class' => 'modalframe-child')); ?> 
		</div>
	<?php endif; ?>
	
</div> <!-- comments-container -->