
Drupal.behaviors.cmtls_place = function(context)
{
	if(context == window.document)
	{
		$('.cmtls-tag-cloud').each(function (i)
		{
			var $this = $(this);
			
			if($this.children('span').length > 15)
			{
				$this.data('original', $this.html());
				
				$this.children('span').slice(14).remove();
				
				$this.append(' <a href="javascript:void(0);" class="cmtls-tag-cloud-more"> &middot; ' + Drupal.t('More') + '..</a>');
			}
		});
		
		$('.cmtls-tag-cloud-more').live('click', function ()
		{
			var $parent = $(this).parent('.cmtls-tag-cloud');
			
			$parent.html($parent.data('original'));
			
			return false;
		});
	}
}