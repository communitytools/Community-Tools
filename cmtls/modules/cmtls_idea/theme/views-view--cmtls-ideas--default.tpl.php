
<?php if($view->args[1]): ?>
	<?php if(!$user->uid && $cmtls['current_group']->field_cmtls_group_posting[0]['value'] == 1 && $cmtls['current_group']->nid == $cmtls['main_group']->nid): ?>
	    <?php print l(t('Add idea'), 'cmtls/login', array('attributes' => array('class' => 'hidden modalframe-child', 'id' => 'add-node-button'))) ?>
	<?php else: ?>
		<?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): print l(t('Add idea'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/idea/add', array('attributes' => array('class' => 'hidden modalframe-child', 'id' => 'add-node-button', 'modal_frame_width' => 820))) ?><?php endif; ?>
	<?php endif; ?>
<?php endif; ?>


<?php if ($rows): ?>
	<?php print $rows; ?>
<?php elseif ($empty): ?>
	<?php print $empty; ?>
<?php endif; ?>