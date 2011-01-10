<?php
/**
 * Variables available:
 * - $app_id: App ID
 * - $pager: pager html
 * 
 */

?><div class="cmtls-problems-container">

	<div class="toolbar">
		<?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): print l(t('+ Add problem'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/problem/add', array('attributes' => array('class' => 'button modalframe-child', 'id' => 'add-problem-button', 'modal_frame_width' => 820))) ?><?php endif; ?> 
	    
		<div class="content-filter-toggle">
			<a href="javascript:void(0);" class="button">v <?php print t('Filter'); ?></a>
	    </div>
	</div> <!-- toolbar -->
	
	<?php print $filter; ?>

	<div id="cmtls-content-container-append">
		<?php print views_embed_view('cmtls_problems', 'default', $app_id); ?>
	</div>

	<?php print $pager; ?>
	
</div>