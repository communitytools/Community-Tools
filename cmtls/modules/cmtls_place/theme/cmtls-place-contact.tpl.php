<?php
/**
 * Variables available:
 * - $node
 * 
 */

if($node->field_cmtls_place_contact[0]['value']): ?><div class="meta-contact"><?php print check_plain($node->field_cmtls_place_contact[0]['value']); ?></div><?php endif; ?>