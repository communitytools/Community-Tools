<?php
/**
 *
 * Variables available:
 * - $node: related node
 *
 */

?><div class="stance-container hidden" id="stance-container-<?php print $node->nid; ?>">
	<?php if ($user->uid): ?>
		<?php print $form; ?>
	<?php else: ?>
		<div class="">
			<?php print t('Please <a !params>log in</a> to submit your stance.', array('!params' => 'href="'.base_path().'cmtls/login" class="modalframe-child"')); ?>
		</div>
	<?php endif; ?>

	<div class="stances-sorted-container" id="stances-sorted-container-<?php print $node->nid; ?>">
		<?php foreach ((array)$node->stances->info['visible stance choices'] as $visible_stance_choice) : ?>
			<?php if ($node->stances->sorted_count[$visible_stance_choice] > 0) : ?>
				<div class="stance">
					<h2><?php print $node->stances->info['stance choices'][$visible_stance_choice]; ?>:</h2>

					<?php foreach ($node->stances->sorted[$visible_stance_choice] as $stance) : ?>
						<div class="meta-author">
							<?php print _cmtls_member_avatar($user->uid == $stance->uid ? $user : $stance->uid, 16, TRUE); ?>
							<?php print $stance->name; ?>
						</div>
					<?php endforeach; ?>
				</div>
			<?php endif; ?>
		<?php endforeach; ?>
	</div>
</div>