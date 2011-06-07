<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

?><h1><?php print _cmtls_edit_button($node); ?><?php print(l($node->title, cmtls_path_to_node($node))); ?></h1>