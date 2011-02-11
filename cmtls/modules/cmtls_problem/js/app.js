
Drupal.behaviors.cmtls_problem = function(context)
{
	if(context == window.document && Drupal.settings.cmtls && Drupal.settings.cmtls.problems && Drupal.settings.cmtls.problems.templates)
	{
		$('.cmtls-problem-comment-template-option').live('change', function ()
		{
			var $this = $(this);
			
			var nid = $this.attr('id').replace('cmtls-problem-comment-template-', '');
			
			var $form = $('#cmtls-comment-form-' + nid);
			
			$('textarea[name="comment"]', $form).val(Drupal.settings.cmtls.problems.templates[$this.val()].template);
		});
	}
}

function cmtlsProblemStatusUpdate(data)
{
	$('#cmtls-problem-status-' + data.options.nid).removeClass('closed').removeClass('open').addClass(data.options.status ? 'closed' : 'open').text(data.options.status_label);
	$('#cmtls-comment-form-' + data.options.nid + ' input[name="problem_status_fixed"], #cmtls-comment-form-' + data.options.nid + ' input[name="problem_status_reported"]').attr('disabled', 'disabled');
}