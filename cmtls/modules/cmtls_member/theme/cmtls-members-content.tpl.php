<?php
/**
 * Variables available:
 * - $group: group
 * - $member_filter_letters: 
 * 
 */

?><div class="cmtls-members-container">

	<div class="members-filter">
		<?php foreach ($member_filter_letters as $key => $l): ?>
			<?php if($key > 0) print ' &middot; ' ?><?php print l($l, 'cmtls/'.$group->nid.'/'.($cmtls['current_app'] && $cmtls['current_app']->field_cmtls_app_type[0]['value'] == 'cmtls_member' ? $cmtls['current_app']->nid : 'members'), array('query' => array('letter' => $l))); ?>
		<?php endforeach; ?>
	</div> <!-- members-filter -->

	<div id="cmtls-content-container-append">
		<?php print views_embed_view('cmtls_members', 'default', $group->nid, ($_GET['letter'] && $_GET['letter'] != t('All') ? $_GET['letter'] : NULL)); ?>
	</div>
	
	<?php print $pager; ?>

</div> <!-- .cmtls-members-container -->