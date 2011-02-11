<div class="cmtls-files-container">

	<div class="content-toolbar">

		<div class="toolbar-description">

			<?php print l('&larr;','cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid,array('html'=>true)) ?>

			<h1><?php print _cmtls_edit_button($cmtls['current_album']->nid) ?> <?php print $title ?></h1>

			<div>
				<?php if($children_count){
					$children_count_container = array();

					foreach($children_count as $type=>$count){
						if($type=='image'){
							$children_count_container[] = t('@photos',array('@photos'=>format_plural($count,'1 photo','@count photos')));
						}elseif($type=='other'){
							$children_count_container[] = t('@documents',array('@documents'=>format_plural($count,'1 document','@count documents')));
						}elseif($type=='video'){
							$children_count_container[] = t('@videos',array('@videos'=>format_plural($count,'1 video','@count videos')));
						}elseif($type=='audio'){
							$children_count_container[] = t('@audiofiles',array('@audiofiles'=>format_plural($count,'1 audio file','@count audio files')));
						}
					}
				} ?>
				<?php if($children_count and !empty($children_count_container)){ print implode(' &middot; ',$children_count_container); } ?>
				<?php print check_plain($cmtls['current_album']->field_cmtls_description[0]['value']); ?>
			</div>

		</div> <!-- toolbar-description -->


		<div class="toolbar-buttons">
			<?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): ?>
				<?php print l(t('Add files'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/album/'.$cmtls['current_album']->nid.'/add', array('attributes' => array('class' => 'cmtls-button-add modalframe-child', 'id' => 'add-images-button'))) ?>
			<?php endif; ?>
		</div>
		<div class="clear"></div>


	</div> <!-- content-toolbar -->


	<div class="gallery">
		<?php if($rows): ?>
			<?php print $rows ?>
		<?php elseif($empty): ?>
			<?php print $empty ?>
		<?php endif ?>
	</div>

</div>