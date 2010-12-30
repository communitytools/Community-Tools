<?php print theme('imagecache','full',$fields['field_cmtls_image_fid']->content,$fields['title']->raw,$field['field_cmtls_description']->raw) ?>

<h1><?php print $fields['title']->raw ?></h1>
<p><?php print $fields['field_cmtls_description_value']->raw ?></p>