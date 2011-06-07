<?php
/**
 * Variables available:
 * 
 * - $node
 * 
 */

$current_group = _cmtls_group_get_current();
$current_app = _cmtls_app_get_current($current_group);

$i = 0;

?><?php if (is_array($node->taxonomy)): ?>
	<?php if (count($node->taxonomy) > 0): ?>
		<div class="meta-tags">
			<?php foreach ($node->taxonomy as $term): ?>
				<?php print l($term->name, 'cmtls/' . $current_group->nid . '/' . $current_app->nid, array('query' => array('tag' => $term->tid), 'attributes' => array('class' => array('category')))); ?>
			<?php endforeach; ?>
		</div> <!-- meta-tags -->
	<?php endif; ?>
<?php endif; ?>