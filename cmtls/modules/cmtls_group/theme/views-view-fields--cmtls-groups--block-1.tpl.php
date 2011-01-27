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

?>
<?php if(!$fields['invite']->content): ?>
<li>
	<h2><?php if($fields['private']->raw): ?><?php print check_plain($fields['title']->raw); ?><?php else: ?><?php print l($fields['title']->raw, 'cmtls/'.$fields['nid']->raw); ?><?php endif; ?></h2><?php if($fields['private']->raw): ?><div class="private"></div><?php endif; ?>
	<div class="groups-meta">
		<?php if($user->uid) print l(($fields['selective']->raw || $fields['private']->raw ? t('Apply to join') : t('Join')), 'cmtls/'.$fields['nid']->raw.'/join', array('attributes' => array('class' => 'modalframe-child '.($fields['selective']->raw || $fields['private']->raw ? 'request-join-button' : 'join-button')))); ?>
	</div>
	
	<?php if($fields['field_cmtls_geoinfo_openlayers_wkt']->raw && $fields['field_cmtls_geoinfo_openlayers_wkt']->raw != 'GEOMETRYCOLLECTION()'): ?>	
		<div class="group-address cmtls-map-popup" id="cmtls-map-feature-<?php print $fields['nid']->raw; ?>">
			<?php print check_plain($fields['field_cmtls_address_value']->raw); ?>
		</div>
	<?php elseif($fields['field_cmtls_address_value']->content): ?>
		<div class="group-address" id="cmtls-map-feature-<?php print $fields['nid']->raw; ?>">
			<?php print check_plain($fields['field_cmtls_address_value']->raw); ?>
		</div>
	<?php endif; ?>
</li>
<?php endif; ?>
