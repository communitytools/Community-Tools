<?php
/**
 * Variables available:
 * - $tags: array of tags
 * 
 */

//printr($tags);

$i = 0;

?><div class="cmtls-tag-cloud"><?php foreach ($tags as $tag): $i++; ?> <span><?php if ($i != 1) print ' &middot; '; print $tag['link']; ?></span> <?php endforeach; ?></div>