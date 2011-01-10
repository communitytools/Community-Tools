<?php
/**
 *
 * Variables available:
 * - $node: related node
 *
 */


?><div class="filter-container">
	<div class="content-filter hidden">
	    <div class="pre-defined">
			<?php $total_predef = sizeof($node->filters->info['filter predefined options']); ?>
			<?php foreach ($node->filters->info['filter predefined options'] as $key => $value): ?>
				<a href="?action=search&predefined_choice=<?php print $key; ?>"><?php print $value['title']; ?></a> <?php if(($key + 1) != $total_predef) print '&middot;'; ?>
			<?php endforeach; ?>
	    </div>
	    <div class="labeled-hr">
	        <span><?php print t('or'); ?></span><hr>
	    </div>
		<?php print $form; ?>
	</div>
</div>