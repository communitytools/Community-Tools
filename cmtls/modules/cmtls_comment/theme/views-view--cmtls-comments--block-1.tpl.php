<?php
// $Id: views-view.tpl.php,v 1.13.4.3 2010/03/25 20:25:16 merlinofchaos Exp $
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 * - $admin_links: A rendered list of administrative links
 * - $admin_links_raw: A list of administrative links suitable for theme('links')
 *
 * @ingroup views_templates
 */
?>
<div id="text-container" class="cmtls-thread-comments-container">

	<?php print l('&larr; '.t('Go back'), _cmtls_app_get_path().'/forum/'.$cmtls['current_forum']->nid, array('html' => TRUE, 'attributes' => array('class' => 'back-button'))); ?>
	<div style="clear: both;"></div>
	
	<div class="forum">
		<h1><?php print l($cmtls['current_forum']->title, _cmtls_app_get_path().'/forum'); ?> &rarr; <?php print l($cmtls['current_thread']->title, _cmtls_app_get_path().'/forum/'.$cmtls['current_forum']->nid); ?></h1>
		<table class="forum-single">
			<tr>
				<td class="author">
					<?php print _cmtls_member_avatar($cmtls['current_thread_author'], 16); ?> <?php print _cmtls_member_name(array('name' => (object)array('raw' => $cmtls['current_thread_author']->name), 'value' => (object)array('raw' => $cmtls['current_thread_author']->profile_cmtls_member_name), 'uid' => (object)array('raw' => $cmtls['current_thread_author']->uid)), TRUE); ?>
				</td>
				<td class="message">
					<?php print check_plain($cmtls['current_thread']->body); ?>
				</td>
				<td class="date">
					<?php print date('d.m.Y H:i', $cmtls['current_thread']->created); ?>
				</td>
			</tr>
			<?php print $rows; ?>
			<?php if($user->uid): ?>
			<tr>
				<td class="author">
					<?php print _cmtls_member_avatar($user, 16); ?> <?php print _cmtls_member_name(array('name' => (object)array('raw' => $user->name), 'value' => (object)array('raw' => $user->profile_cmtls_member_name), 'uid' => (object)array('raw' => $user->uid)), TRUE); ?>
				</td>
				<td class="message">
					<?php print drupal_get_form('comment_form', array('nid' => $view->args[0])); ?>
				</td>
				<td class="date">
				</td>
			</tr>
			<?php endif; ?>
			
		</table>
	</div>
</div>
				


