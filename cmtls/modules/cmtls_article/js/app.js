
Drupal.behaviors.cmtls_article = function(context)
{
	if (context == window.document)	{		
		$('.node-teaser-to-full').live('click', function () {
			var nid = $(this).attr('data-nid');
			
			$('.node-teaser[data-nid="' + nid + '"]').addClass('hidden');
			$('.node-full[data-nid="' + nid + '"]').removeClass('hidden');
			
			return false;
		});
		
		$('.node-full-to-teaser').live('click', function () {
			var nid = $(this).attr('data-nid');
			
			$('.node-full[data-nid="' + nid + '"]').addClass('hidden');
			$('.node-teaser[data-nid="' + nid + '"]').removeClass('hidden');
			
			return false;
		});
	}
}
