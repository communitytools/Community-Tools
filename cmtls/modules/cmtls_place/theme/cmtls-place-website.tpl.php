<?php
/**
 * Variables available:
 * - $node
 * 
 */

// add http:// if necessarry


if($node->field_cmtls_place_website[0]['value'])
{
	$href = trim($node->field_cmtls_place_website[0]['value']);
	if(strpos($href, 'http') !== 0) $href = 'http://'.$href;
}

if($node->field_cmtls_place_website[0]['value']): ?><div class="meta-website"><?php print l($node->field_cmtls_place_website[0]['value'], $href, array('external' => TRUE, 'attributes' => array('target' => '_blank'))); ?></div><?php endif; ?>