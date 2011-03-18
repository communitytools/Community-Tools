<?php
/**
 * Variables available:
 * - $current_date: array with current date
 * - $selected_date: array with selected date
 * - $days: array of days
 *
 */

?><div class="cmtls-horizontal-calendar">

    <div class="cmtls-horizontal-calendar-navi">

        <?php print t($selected_date['month_title']); ?>
        <?php print $selected_date['year']; ?>
    
    </div> <!-- cmtls-horizontal-calendar-navi -->
    
    <div class="cmtls-horizontal-calendar-dates">

        <a href="<?php print url('cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid, array('query' => array('year' => $selected_date['month'] == 1 ? $selected_date['year'] - 1 : $selected_date['year'], 'month' => $selected_date['month'] == 1 ? 12 : $selected_date['month'] - 1), 'absolute' => TRUE)); ?>" id="cmtls-horizontal-calendar-previous">&laquo;</a>        
        
        <?php foreach ($days as $day_nr => $day): ?><span <?php if($day['weekday'] == 6) print ' class="saturday"' ?><?php if($day['weekday'] == 7) print ' class="sunday"' ?>><?php if($day['is_today']) print '<strong>' ?><?php if($day['has_events']): print l($day_nr, 'cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid, array('query' => $day['query'])); ?><?php else: print $day_nr; ?><?php endif; ?><?php if($day['is_today']) print '</strong>' ?></span><?php endforeach; ?>
        
        <a href="<?php print url('cmtls/'.$cmtls['current_group']->nid.'/'.$cmtls['current_app']->nid, array('query' => array('year' => $selected_date['month'] == 12 ? $selected_date['year'] + 1 : $selected_date['year'], 'month' => $selected_date['month'] == 12 ? 1 : $selected_date['month'] + 1), 'absolute' => TRUE)); ?>" id="cmtls-horizontal-calendar-next">&raquo;</a>
        
    </div> <!-- cmtls-horizontal-calendar-dates -->
	
</div> <!-- cmtls-horizontal-calendar -->



