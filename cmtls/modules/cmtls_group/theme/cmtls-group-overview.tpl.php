<?php
/**
 * Variables available:
 * - $group: group node
 * - $apps: apps overviews
 * - $page: group or members
 * - $members: members list
 *
 */

$tabs = array(
	'page' => array(
		'title' => t('Overview'),
		'rel' => '#cmtls-group-overview-content',
		'anchor' => 'overview'
	),
	'members' => array(
		'title' => t('Members'),
		'rel' => '#cmtls-group-members-content',
		'anchor' => 'members'
	),
);

?><div class="cmtls-group-overview-container">

	<div class="content-toolbar">

		<div class="toolbar-description">
			<h1><?php print _cmtls_edit_button($group->nid); ?><?php print check_plain($group->title); ?></h1>
			<p>
				<?php print format_plural($group->posts,'1 post','@count posts'); ?>
				&middot; <?php print format_plural($group->comments,'1 comment','@count comments'); ?>
				&middot; <?php print format_plural($group->members,'1 member','@count members'); ?>
				&middot; <?php print check_plain($group->og_description); ?>
			</p>
		</div>
		<div class="clear"></div>
		
		<?php if(sizeof($tabs)): ?>
		
			<ul class="toolbar-tabs">
			<?php foreach($tabs as $key => &$tab): ?>
				<li<?php print $key == $page ? ' class="selected"' : NULL; ?>><a href="#<?php print $tab['anchor'] ?>" rel="<?php print $tab['rel'] ?>"><?php print $tab['title'] ?></a></li>
			<?php endforeach; ?>
				
		<?php endif; ?>
		
	</div> <!-- content-toolbar -->

	<div id="cmtls-group-overview-content" class="group-overview<?php print $page == 'members' ? ' hidden' : NULL; ?>">

		<?php foreach ($apps as $app): ?>
		<div class="group-tool">
			<div class="group-name">
				<?php print l($app['title'], 'cmtls/'.$group->nid.'/'.$app['nid']); ?>
			</div>
			<div class="group-posts">
				<?php print $app['posts column']; ?>
			</div>
			<div class="group-comments">
				<?php print $app['comments column']; ?>
			</div>
			<div class="clear"></div>
		</div> <!-- group-tool -->
		<?php endforeach; ?>

	</div> <!-- group-overview -->
	
	<div id="cmtls-group-members-content" class="group-overview<?php print $page == 'group' ? ' hidden' : NULL; ?>">
	
		<?php print $members; ?>

	</div> <!-- group-overview -->

</div> <!-- cmtls-group-overview-container -->