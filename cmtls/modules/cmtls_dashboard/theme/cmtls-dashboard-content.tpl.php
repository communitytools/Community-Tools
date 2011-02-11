<?php
/**
 * Variables available:
 * - $apps
 * - $widgets
 *
 */
?>

<?php if(!$user->uid && $cmtls['current_group']->field_cmtls_group_posting[0]['value'] == 1 && $cmtls['current_group']->nid == $cmtls['main_group']->nid): ?>
    <?php print l('+ '.t('Add'), 'cmtls/login', array('attributes' => array('class' => 'hidden modalframe-child', 'id' => 'add-node-button'))) ?>
<?php else: ?>
    <?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): print l('+ '.t('Add'), 'cmtls/'.$cmtls['current_group']->nid.'/map/choose-app', array('attributes' => array('class' => 'hidden modalframe-child', 'id' => 'add-node-button', 'modal_frame_width' => 820))) ?><?php endif; ?>
<?php endif; ?>

<?php print $cmtls_content_header ;?>


<div class="cmtls-dashboard-container">

	<?php if(sizeof($apps)): ?>
	<div class="dashboard-main">
	
		<?php foreach ($apps as &$app): ?>
		
			<div class="content-group-header">
				<a href="<?php print base_path().'cmtls/'.$cmtls['current_group']->nid.'/'.$app->nid; ?>"><span><?php print check_plain($app->title); ?></span></a>
			</div>
			<div class="text-node">
				<?php print $app->cmtls_dashboard_content; ?>
			</div>
	
		<?php endforeach; ?>
	
	</div> <!-- left -->
	<?php endif; ?>
	
	<?php if(sizeof($widgets)): ?>
	<div class="dashboard-widgets">
	
		<?php foreach ($widgets as &$widget): ?>
		
			<div class="content-group-header">
				<span><?php print check_plain($widget['title']); ?></span>
			</div>
			<div class="text-node">		
				<?php print $widget['content']; ?>
			</div>
		
		<?php endforeach; ?>
	
	</div> <!-- right -->
	<?php endif; ?>

</div> <!-- cmtls-dashboard-container -->