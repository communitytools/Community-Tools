<?php
/**
 * Variables available:
 * - $node
 * 
 */

if($node->field_cmtls_place_email[0]['value']): ?><div class="meta-email"><?php print l($node->field_cmtls_place_email[0]['value'], 'mailto:'.$node->field_cmtls_place_email[0]['value'], array('external' => TRUE)); ?></div><?php endif; ?>