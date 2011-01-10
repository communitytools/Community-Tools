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
<div class="cmtls-threads-container">

	<div class="toolbar">
		<?php print l('&larr; '.t("Back to topics' page"), _cmtls_app_get_path().'/forum', array('html' => TRUE, 'attributes' => array('class' => 'back-button'))); ?>
		<?php if($user->uid && og_is_group_member($cmtls['current_group'], TRUE, $user->uid)) print l(t('+ Start a thread'), _cmtls_app_get_path().'/forum/'.$cmtls['current_forum']->nid.'/add', array('attributes' => array('class' => 'button add modalframe-child'))); ?>
	</div> <!-- toolbar -->
						
	<div class="forum">
		<h1><?php print l($cmtls['current_forum']->title, _cmtls_app_get_path().'/forum'); ?></h1>
		<div class="forum-discussions-list">
			<ul>
				<?php print $rows; ?>
			</ul>
		</div>
	</div>
</div>