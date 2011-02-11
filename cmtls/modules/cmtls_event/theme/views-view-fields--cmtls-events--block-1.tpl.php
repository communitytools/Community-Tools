<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

$node = node_load($fields['nid']->raw);

$start_date = date('d.m.Y', strtotime($node->field_cmtls_event_date[0]['value']));
$start_time = date('H:i', strtotime($node->field_cmtls_event_date[0]['value']));
$end_date = date('d.m.Y', strtotime($node->field_cmtls_event_date[0]['value2']));
$end_time = date('H:i', strtotime($node->field_cmtls_event_date[0]['value2']));

if ($node->field_cmtls_event_lasts_all_day[0]['value'])
{
	$time = ($start_date == $end_date) ? $start_date : $start_date.' - '.$end_date;
}
else
{
	$time = $start_date.' '.$start_time.($end_date || $end_time ? ' - ' :'').($end_date && $start_date != $end_date ? $end_date.' ' : '').$end_time;
}

?>

<div class="dashboard-item">
	<?php print l($fields['title']->raw, cmtls_path_to_node($fields['nid']->raw, $cmtls['current_group'])); ?>
	<span class="dashboard-meta">&middot; <?php print $time; ?></span>
</div><!-- dashboard-item -->

