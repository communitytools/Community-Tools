<?php
// $Id$

$total_pages = floor($view->total_rows / $view->pager['items_per_page']);

$vars = array(
	'cmtls' => array(
		'pager' => array(
			'totalPages' => $total_pages,
			'currentPage' => $view->pager['current_page'],
			'totalItems' => $view->total_rows,
		),
	),
);

drupal_add_js($vars, 'setting');

?>
	
<div class="<?php print $classes; ?>">
<?php if ($rows): ?>
	<?php print $rows; ?>
<?php elseif ($empty): ?>
	<?php print $empty; ?>
<?php endif; ?>

</div>