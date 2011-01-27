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

<?php if(sizeof($apps)): ?>
<div class="dashboard-1">

<?php foreach ($apps as &$app): ?>
	<div class="item">
		<div class="dashboard-item"><div class="content">
			<div class="title"><?php print check_plain($app->title); ?></div>
			<?php print l(t('See all'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$app->nid, array('attributes' => array('class' => 'see-all-link'))); ?>
			<?php print $app->cmtls_dashboard_content; ?>
		</div></div>
	</div>
<?php endforeach; ?>

</div>
<?php endif; ?>

<?php if(sizeof($widgets)): ?>
<div class="dashboard-2">

<?php foreach ($widgets as &$widget): ?>
	<div class="item">
		<div class="dashboard-item"><div class="content">
			<div class="title"><?php print $widget['title']; ?></div>
			<?php print $widget['content']; ?>
		</div></div>
	</div>
<?php endforeach; ?>

</div>
<?php endif; ?>