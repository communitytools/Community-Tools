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

<?php if($view->args[1]): ?>
	<?php if(!$user->uid && $cmtls['current_group']->field_cmtls_group_posting[0]['value'] == 1 && $cmtls['current_group']->nid == $cmtls['main_group']->nid): ?>
	    <?php print l(t('Add problem'), 'cmtls/login', array('attributes' => array('class' => 'hidden modalframe-child', 'id' => 'add-node-button'))) ?>
	<?php else: ?>
		<?php if(cmtls_group_can_create_content($cmtls['current_group'], $user)): print l(t('Add problem'), 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid.'/problem/add', array('attributes' => array('class' => 'hidden modalframe-child', 'id' => 'add-node-button', 'modal_frame_width' => 820))) ?><?php endif; ?> 
	<?php endif; ?>
<?php endif; ?>

<?php if ($rows): ?>
	<?php print $rows; ?>
<?php elseif ($empty): ?>
	<?php print $empty; ?>
<?php endif; ?>

</div>