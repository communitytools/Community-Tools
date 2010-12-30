<?php
// $Id: views-view-unformatted.tpl.php,v 1.6.6.1 2010/03/29 20:05:38 dereine Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

$today = strtotime('today');
$today_name = date('l', $today);

$tomorrow = $today + 60 * 60 * 24;
$tomorrow_name = date('l', $tomorrow);

$current_year = date('Y', $today);

$dividers = array();

foreach($view->result as $id => $result)
{
	$start_timestamp = strtotime($result->node_data_field_cmtls_event_date_field_cmtls_event_date_value);
	
	$start_year = date('Y', $start_timestamp);
	$start_date = date('d.m', $start_timestamp).($current_year != $start_year ? '.'.$start_year : '');

	if(date('d.m', $today) == $start_date)
	{
		$dividers['Today, '.$today_name.' '.$start_date][] = $id;
	}
	else if(date('d.m', $tomorrow) == $start_date)
	{
		$dividers['Tomorrow, '.$tomorrow_name.' '.$start_date][] = $id;
	}
	else
	{
		$dividers[date('l', $start_timestamp).' '.$start_date][] = $id;
	}
}

?>
<?php foreach ($dividers as $divider => $row_ids): ?>
	<div class="event-group-header">
		<?php print $divider; ?>
	</div>
	<div class="article-node">
		<?php foreach ($row_ids as $id): ?>
			<div class="content">
				<?php print $rows[$id]; ?>
			</div>
		<?php endforeach; ?>
	</div>
<?php endforeach; ?>

