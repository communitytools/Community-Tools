<?php

//printr($user); exit;
//printr($cmtls); exit;

?><!DOCTYPE html>
<html dir="<?php print $language->dir; ?>" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" xmlns="http://www.w3.org/1999/xhtml" xmlns:fb="http://www.facebook.com/2008/fbml">

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
	<!--[if lt IE 8]>
		<style type="text/css">
			li a {display:inline-block;}
			li a {display:block;}
		</style>
	<![endif]-->
  <?php print $scripts; ?>
</head>
<body style="background-image: url(<?php print $cmtls['current_group_properties']['background_image']; ?>);">
	<div class="filters">
			<a href="javascript:void(0);" onclick="mapLocationSwitcer('map-only');"><?php print t('Map'); ?></a> |
			<a href="javascript:void(0);" onclick="mapLocationSwitcer('text-map');"><?php print t('Map and Text'); ?></a> |
			<a href="javascript:void(0);" onclick="mapLocationSwitcer('text-only');"><?php print t('Text'); ?></a>
	</div>
	<div id="header">		
		<div class="header-container">	
		
			<div id="cmtls-site-menu">
				<ul>
					<li><a href="" class="select-group-menu"><span><?php print ($user->uid ? t('My groups') : t('Groups')); ?></span></a></li>
				</ul>		
				<?php print $cmtls_site_menu; ?>
			</div>
			
			<?php if($user->uid): ?>
				<?php print views_embed_view('cmtls_groups', 'default', $user->uid); ?>
			<?php else: ?>
				<?php print views_embed_view('cmtls_groups', 'default'); ?>
			<?php endif; ?>
			
			<div class="community-name">
				<?php print l('', $base_url, array('attributes' => array('class' => 'ct-logo-small', 'target' => '_blank'))); ?>
				<div class="community-title"><?php print l($cmtls['main_group']->title, 'cmtls/'.$cmtls['main_group']->nid); ?></div>
				<div class="arrow-right">&gt;</div>
				<div class="current-group-name"><?php print l($cmtls['current_group']->title, 'cmtls/'.$cmtls['current_group']->nid, array('attributes' => array('class' => ($cmtls['current_group']->og_private ? 'closed' : '')))); ?></div>
				<?php if($user->uid): ?>
					<?php if(og_is_group_member($cmtls['current_group'], FALSE)): ?>
						<?php print l(t('(Members)'), 'cmtls/'.$cmtls['current_group']->nid.'/members', array('attributes' => array('class' => 'ct-members-join'))); ?>
					<?php else: ?>
						<?php print l(t('(Join group)'), 'cmtls/'.$cmtls['current_group']->nid.'/join', array('attributes' => array('class' => 'ct-members-join modalframe-child'))); ?>
					<?php endif; ?>
				<?php endif; ?>
			</div>
		
			<?php print l('', $base_url, array('attributes' => array('class' => 'back-to-website-button'))); ?>
	
		</div>
		
		<div class="background-image" style="background-image: url(<?php print $cmtls['current_group_properties']['background_image']; ?>);"></div>
		
		<div class="background"></div>
		
		<?php /*
		<div class="community-name">
			<?php print l($cmtls['main_group']->title, 'cmtls/'.$cmtls['main_group']->nid); ?>
			<div class="ct-credit">
				<a href="http://www.communitytools.info">Community Tools</a>
			</div>
		</div>*/ ?>
		
		<?php if($user->uid): ?>	
		<div class="profile-background">
			<ul class="profile-selector">
				<li>
					<a href="javascript:void(0);"><?php print t('My stuff'); ?></a>
					<ul class="hidden">
						<li><?php print l(t('Profile'), 'cmtls/'.$cmtls['main_group']->nid.'/member/'.$user->uid); ?></li>
						<?php /*<li><?php print l('Seaded', 'user/'.$user->uid.'/edit'); ?></li> */ ?>
						<li><?php print l(t('Groups'), 'cmtls/list'); ?></li>
						<li><?php print l(t('Log out'), 'logout'); ?></li>
					</ul>
				</li>
			</ul>
		</div>
		
		<?php else: ?>
		<div class="profile-background">
			<ul class="profile-selector">
				<li>
					<a href="javascript:void(0);"><?php print t('Member'); ?></a>
					<ul class="hidden">
						<li><?php print l(t('Login'), 'cmtls/login', array('attributes' => array('class' => 'modalframe-child'))); ?></li>
						<li><?php print l(t('Register'), 'cmtls/register', array('attributes' => array('class' => 'modalframe-child'))); ?></li>
					</ul>
				</li>
			</ul>
		</div>
		<?php endif; ?>
		
		<?php /* <input class="global-search" type="text" name="some_name" value="Otsing " id="some_name"> */ ?>
		
	</div>
	
	<?php print views_embed_view('cmtls_apps', 'default', $cmtls['current_group']->nid); ?>
	
	<div id="content" class="<?php print $cmtls['map']['class'] ? $cmtls['map']['class'] : 'text-only'; ?>">
		<div id="text-container">
			<?php print $content; ?>
		</div>
		
		<div id="map"><?php print $cmtls['map']['output']; ?></div>
	</div>

	<script type='text/javascript'>
	      var _ues = {
	      host:'communitytools.userecho.com',
	      forum:'1139',
	      lang:'en',
	      tab_alignment:'right',
	      tab_text_color:'white',
	      tab_bg_color:'#3C8A2E',
	      tab_hover_color:'#163D0E'
	      };
	      
	      (function() {
		  var _ue = document.createElement('script'); _ue.type = 'text/javascript'; _ue.async = true;
		  _ue.src = ('https:' == document.location.protocol ? 'https://s3.amazonaws.com/' : 'http://') + 'cdn.userecho.com/js/widget-1.4.gz.js';
		  var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(_ue, s);
		})();
	</script>
	
	<?php print $closure ?>
	
</body>
</html>
