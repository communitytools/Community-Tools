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
<div class="cmtls-forums-container">

	<div class="content-toolbar">
		<h1><?php print check_plain($cmtls['current_app']->title); ?></h1>
	</div> <!-- content-toolbar -->

	<div class="forum">
		<div class="forum-topics-list">
			<ul>
				<?php print $rows; ?>
				<li class="add-group-button">
					<?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)) print l(t('+ Add topic'), _cmtls_app_get_path().'/forum/add', array('attributes' => array('class' => 'modalframe-child'))); ?>
				</li>
		</div>
	</div>
</div>