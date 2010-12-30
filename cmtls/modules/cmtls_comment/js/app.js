
Drupal.behaviors.cmtls_comment = function(context)
{
	if(context == window.document)
	{
		// ajax load comments on toggle
		$('.cmtls-comment-toggle-button').live('click', function()
		{
			var $this = $(this);
			var nid = $this.attr('id').replace('cmtls-comments-toggle-button-', '');
			
			if(Drupal.settings.cmtls.comments.loadCommentsWithAjax)
			{
				var data = $this.data('cmtls_comments');
				
				if(typeof(data) == 'undefined' || (typeof(data) != 'undefined' && !data.comments_loaded)) 
				{
					$.ajax({
						type: 'POST',
						url: Drupal.settings.basePath + 'cmtls/comments/' + nid + '/ajax',
						success: function (data, textStatus, XMLHttpRequest)
						{
							if(data.content)
							{
								$('#cmtls-comments-' + nid).html(data.content);
								$('#cmtls-comments-loading-' + nid).addClass('hidden');
							}
							
							$this.data('cmtls_comments', {comments_loaded: true});
							
						},
						error: function (XMLHttpRequest, textStatus, errorThrown)
						{
							alert(textStatus);
						},
						dataType: 'json',
						data: {ajax: 1}
					});
				}
			}
			
			$('#comments-container-' + nid).slideToggle('slow,');
					
			return false;
		});
		
		$('.comment-form .form-submit').live('click', function ()
		{
			var $submit = $(this);
			var $this = $(this.form);
			var nid = $this.parent().attr('id').replace('cmtls-comment-form-', '');
			
			if($('textarea[name="comment"]', $this).val().length > 0)
			{
				$submit.attr('disabled', 'disabled');
				
				var submitVal = $submit.val();
				$submit.val(Drupal.t('Saving ...'));
				
				$.ajax({
					type: $this.attr('method'),
					url: $this.attr('action'),
					dataType: 'json',
					data: $this.serialize() + '&ajax=1',
					success: function (data, textStatus, XMLHttpRequest)
					{
						if(data.content)
						{
							$('#cmtls-comments-' + nid).html(data.content);
							$('textarea[name="comment"]', $this).val('');
						}
						
						$submit.val(submitVal);
						$submit.removeAttr('disabled');
					},
					error: function (XMLHttpRequest, textStatus, errorThrown)
					{
						$submit.val(submitVal);
						$submit.removeAttr('disabled');
						alert(textStatus);
					}
				});
			}
			
			return false;
		});
	}
};
