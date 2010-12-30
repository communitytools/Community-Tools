<?php if ($rows): ?>
    <div class="gallery-container">
	<?php print $rows; ?>
    </div>
<?php elseif ($empty): ?>
	<?php print $empty; ?>
<?php endif; ?>
