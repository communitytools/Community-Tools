jQuery(function($){
	CMTLSUploader.init();
})


var CMTLSUploader = function(){
	// General variables
	var uploader,_settings,settings;
	// Handler variables
	var fileUploadedBytes = 0;
	var filesUploadedBytes = 0;
	var filesTotalBytes = 0;
	var currentFileIndex = 0;
	var currentFile;
	var fileCount = 0;
	var successfulUploads = 0;
	var failedFiles = [];
	
	var notificationTemplates = {
		filesQueued:Drupal.t('%count files in queue. %totalsize %unit in total'),
		fileQueueError:Drupal.t('Error queueing file <strong>%filename</strong>. %message'),
		uploadProgress:'Uploading file <strong id="upload-file-name">%filename</strong> <span id="upload-percentage">0%</span> (<span id="upload-file-index">%index</span>/<span id="upload-file-count">%filecount</span>)',
		uploadComplete:Drupal.t('%success files of %filecount uploaded successfully'),
		error401:Drupal.t("Error uploading file <strong>%file</strong>. Seems that the uploader doesn't have permissions to access your server (error code 401: Unauthorized)"),
		error403:Drupal.t("Error uploading file <strong>%file</strong>. Seems that the uploader doesn't have permissions to access your server (error code 403: Forbidden)")
	}

	var handlers = {
		fileDialogStart: function(){
			filesUploadedBytes = 0;
			//filesTotalBytes = 0;
			currentFileIndex = 0;
			currentFile = {};
			fileCount = 0;
			successfulUploads = 0;
		},
		fileQueued: function(file){
			filesTotalBytes += file.size;
		},
		fileQueueError: function(file,error,message){
			visuals.setNotificationMessage('error',notificationTemplates.fileQueueError,{filename:file.name,message:message});
		},
		fileDialogComplete: function(filesSelected,filesQueued,filesInQueue){
			fileCount = filesInQueue;

			if(filesInQueue>0){
				visuals.setStatusMessage('filesQueued',{
					filesTotalBytes:filesTotalBytes,
					fileCount:filesInQueue
				});
				
				jQuery('#start-upload')
					.removeAttr('disabled')
					.button('refresh')
			}
		},
		uploadStart: function(file){
			currentFileIndex++;
			currentFile = file;
			fileUploadedBytes = 0;
			visuals.setStatusMessage('uploadProgress',{filename:file.name,index:currentFileIndex,filecount:fileCount});
			jQuery('#cancel-upload').show();
		},
		uploadProgress: function(file,bytesComplete,totalBytes){
			filesUploadedBytes += bytesComplete-fileUploadedBytes;
			fileUploadedBytes = bytesComplete;

			visuals.updateUploadProgress(bytesComplete,totalBytes,filesUploadedBytes);
		},
		uploadError: function(file,error,message){
			visuals.setNotificationMessage('error','error'+message,{file:file.name});
		},
		uploadSuccess: function(file,data,response){
			successfulUploads++;
		},
		uploadComplete: function(file){
		},
		queueComplete: function(){
			visuals.setStatusMessage('uploadComplete',{success:successfulUploads,filecount:fileCount});
			
			jQuery('#start-upload')
				.attr('disabled',true)
				.addClass('disabled');

			jQuery('#cancel-upload').hide();

			if(successfulUploads>0){
				jQuery('#edit-submit')
					.removeAttr('disabled')
					.removeClass('disabled')
					.button('refresh');
				jQuery('#start-upload')
					.attr('disabled',true)
					.addClass('disabled')
					.button('refresh');				
			}
		}
	}
	
	var visuals = {
		updateUploadProgress: function(bytesComplete,totalBytes,filesUploadedBytes){
			var fileState = Math.floor(bytesComplete/totalBytes*100);
			var totalState = Math.floor(filesUploadedBytes/filesTotalBytes*100);
			
			jQuery('#progressbar').css('width',totalState+'%');
			jQuery('#upload-percentage','#upload-status-message').text(fileState+'%');
		},
		setNotificationMessage: function(type,template,data){
			template = notificationTemplates[template];

			var message = jQuery('<p>')
				.addClass(type)
				.html(helpers.compileMessageString(template,data));

			jQuery('#upload-notification-messages').append(message);
		},
		setStatusMessage: function(type,data){
			var template,messageString;

			switch(type){
				case 'filesQueued':
					var size,unit;
					template = notificationTemplates.filesQueued;

					if (data.filesTotalBytes>1048576) {
						size = Math.round(data.filesTotalBytes/1048576*10)/10;
						unit = 'M';
					}
					else if(data.filesTotalBytes>1024){
						size = Math.round(data.filesTotalBytes/1024);
						unit = 'K';
					}

					messageString = helpers.compileMessageString(template,{count:data.fileCount,totalsize:size,unit:unit});
					break;
				default:
					template = notificationTemplates[type];
					messageString = helpers.compileMessageString(template,data);
			}

			jQuery('#upload-status-message').html(messageString);
		},
		setUpUploader: function(){
			var status = false;

			// Set up progressbar, upload buttons etc.
			jQuery('input[type=file]').each(function(index,element){
				jQuery(element).hide();
				jQuery(element).siblings('label').hide();
				
				var uploadButtonsWrapper = jQuery('<div>')
					.attr('id','upload-buttons')
					.addClass('upload-buttons');
				
				var addFilesButton = jQuery('<div>')
					.attr('id','add-files')
					.text(Drupal.t('Add files'))
					.append('<span id="upload-button-placeholder"></span>');
				
				var startUploadButton = jQuery('<button>')
					.attr('id','start-upload')
					.text(Drupal.t('Start upload'))
					.attr('disabled',true)
					.bind('click',function(event){
						CMTLSUploader.startUpload();
						return false;
					});
				
				var cancelUploadButton = jQuery('<button>')
					.attr('id','cancel-upload')
					.attr('href','#cancel-upload')
					.text(Drupal.t('Cancel all uploads'))
					.css('display','none');
				
				uploadButtonsWrapper
					.append(addFilesButton)
					.append(startUploadButton)
					.append(cancelUploadButton)
					
				jQuery(element).after(uploadButtonsWrapper);

				jQuery('#edit-submit')
					.val(Drupal.t('Continue'))
					.addClass('disabled')
					.attr('disabled',true)
					.button('refresh');
				
				// jQuery UI sytles 
				$('#add-files').button({icons: {primary:'ui-icon-plus'}});
				$('#start-upload').button({icons: {primary:'ui-icon-disk'}});
				$('#cancel-upload').button({icons: {primary:'ui-icon-cancel'}});
				
				status = true;
			});
			
			return status;
		},
		finishSettingUpLoader: function(){
			jQuery('.swfupload').each(function(index,element){
				var wrapper = jQuery(element).parents('div');
				
				jQuery(element)
					.attr('width',wrapper.outerWidth())
					.attr('height',wrapper.outerHeight())
			})
		}
	}
	
	var helpers = {
		compileMessageString: function(string,replacements){
			for(var i in replacements){ string = string.replace('%'+i,replacements[i]); }

			return string;
		}
	}

	var init = function(){
		var status = visuals.setUpUploader();
		
		if(!status){ return; }

		_settings = CMTLSUploadSettings;
		
		settings = {
			flash_url:_settings.modulepath+'/js/swfupload/swfupload.swf',
			upload_url:_settings.uploadpath,
			post_params:{
				PHPSESSID:_settings.sessionid,
				nodetype:_settings.nodetype,
				fieldname:_settings.fieldname
			},
			// File settings
			file_post_name:'Filedata',
			file_size_limit:_settings.maxfilesize,
			file_types:_settings.fileextensions,
			file_types_description:'Album objects',
			file_upload_limit:_settings.uploadlimit,
			file_queue_limit:0,
			debug:false,
			// Button settings
			button_width:0,		// will be set later
			button_height:0,	// will be set later
			button_placeholder_id:'upload-button-placeholder',
			//button_image_url:_settings.modulepath+'/js/swfupload/select_images.png',
			button_cursor:SWFUpload.CURSOR.HAND,
			button_window_mode:SWFUpload.WINDOW_MODE.TRANSPARENT,
			// Event handlers
			file_dialog_start_handler:handlers.fileDialogStart,
			file_queued_handler:handlers.fileQueued,
			file_queue_error_handler:handlers.fileQueueError,
			file_dialog_complete_handler:handlers.fileDialogComplete,
			upload_start_handler:handlers.uploadStart,
			upload_progress_handler:handlers.uploadProgress,
			upload_error_handler:handlers.uploadError,
			upload_success_handler:handlers.uploadSuccess,
			upload_complete_handler:handlers.uploadComplete,
			queue_complete_handler:handlers.queueComplete
		}
		
		uploader = new SWFUpload(settings);
		
		visuals.finishSettingUpLoader();
	}

	return {
		init: function(){
			init();
		},
		uploader: uploader,
		startUpload: function(){
			uploader.startUpload();
		}
	}
}();