<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

?><?php print l($node->comment_count ? format_plural($node->comment_count,'1 comment','@count comments') : t('Comment'), cmtls_path_to_node($node), array('attributes' => array('class' => 'comments-button cmtls-comment-toggle-button', 'id' => 'cmtls-comments-toggle-button-'.$node->nid))); ?>
