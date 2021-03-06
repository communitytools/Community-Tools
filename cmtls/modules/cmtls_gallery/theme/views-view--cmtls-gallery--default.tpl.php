<div class="cmtls-folders-container">

	<div class="content-toolbar">
		
		<h1><?php print check_plain($cmtls['current_app']->title); ?></h1>

		<div class="toolbar-buttons">
			<?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): ?>
				<?php print l(t('Add folder'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/album/add', array('attributes' => array('class' => 'cmtls-button-add modalframe-child', 'id' => 'add-album-button'))) ?>
				<div class="clear"></div>
			<?php endif; ?>
		</div>
	</div> <!-- content-toolbar -->
	
    <div class="gallery<?php if(!empty($classes)): ?> <?php print $classes ?><?php endif ?>">
    
    <?php if($rows): ?>
            <?php print $rows ?>
    <?php elseif($empty): ?>
            <?php print $empty ?>
    <?php endif ?>	
    </div>
</div>