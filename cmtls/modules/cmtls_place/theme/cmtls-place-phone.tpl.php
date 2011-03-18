<?php
/**
 * Variables available:
 * - $node
 *
 */

if($node->field_cmtls_place_phone[0]['value']): ?><div class="meta-phone"><?php print l($node->field_cmtls_place_phone[0]['value'], 'tel:'.$node->field_cmtls_place_phone[0]['value'], array('external' => TRUE)); ?></div><?php endif; ?>