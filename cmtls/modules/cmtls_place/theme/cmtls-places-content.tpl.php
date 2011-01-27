<?php
/**
 * Variables available:
 * - $app_id: App ID
 * - $pager: pager html
 * 
 */

?>
<div class="cmtls-places-container">
    
	<div class="toolbar">
	
		<?php if(!$user->uid && $cmtls['current_group']->field_cmtls_group_posting[0]['value'] == 1 && $cmtls['current_group']->nid == $cmtls['main_group']->nid): ?>
		    <?php print l(t('Add place'), 'cmtls/login', array('attributes' => array('class' => 'cmtls-button-add modalframe-child', 'id' => 'add-node-button'))) ?>
		<?php else: ?>
		    <?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): print l(t('Add place'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/place/add', array('attributes' => array('class' => 'cmtls-button-add modalframe-child', 'id' => 'add-node-button', 'modal_frame_width' => 820))) ?><?php endif; ?>
		<?php endif; ?>

		<a href="javascript:void(0);" class="button">v <?php print t('Filter'); ?></a>

	</div> <!-- toolbar -->
	
	<?php print $filter; ?>
    
	<div id="cmtls-content-container-append">
        <?php print views_embed_view('cmtls_places', 'default', $app_id); ?>
    </div>

    <?php print $pager; ?>
    
</div>