/* Groups toggle */
function initGroups() {
  $('.groups-selector ul').hide();
  $('.groups-selector li a').click(
    function() {
        $(this).next().slideToggle('normal');
      }
    );
  }
$(document).ready(function() {initGroups();});


/* Profile toggle */
function initProfile() {
  $('.profile-selector ul').hide();
  $('.profile-selector li a').click(
    function() {
        $(this).next().slideToggle('normal');
      }
    );
  }
$(document).ready(function() {initProfile();});


/* Toggle filters */
jQuery(document).ready(function(){

	jQuery(".toggle_container").hide();

	jQuery(".filter-button").toggle(function(){
		jQuery(this).addClass("active");
		}, function () {
		jQuery(this).removeClass("active");
	});

	jQuery(".filter-button").click(function(){
		jQuery(this).next(".toggle_container").slideToggle("slow,");
	});

});

/* **** DROP-DOWN **** */
$(document).ready(function() {

    $(".select-group-menu").click(function(e) {
		e.preventDefault();
        $("div#select-group-menu-panel").toggle();
		$(".select-group-menu").toggleClass("menu-open");
    });

	$("div#select-group-menu-panel").mouseup(function() {
		return false
	});
	$(document).mouseup(function(e) {
		if($(e.target).parent("a.select-group-menu").length==0) {
			$(".select-group-menu").removeClass("menu-open");
			$("div#select-group-menu-panel").hide();
		}
	});

});

// display user warning for older IE browsers
$(function ()
{
	if($.browser.msie)
	{
		var version = $.browser.version.split('.');
		
		if(parseInt(version[0]) < 8 && $.cookie('browser_warning_close') != 1)
		{
			$('body').append('<div id="cmlts-browser-warning"><p>' + Drupal.t('Sorry, our website only supports Internet Explorer version 8 and newer. Please upgrade.') + '</p><a class="cmtls-button" href="javascript:void(0);" onclick="closeBrowserWarning(this)">' + Drupal.t('Close') + '</a></div>');
		}
	}
});

function closeBrowserWarning(a)
{
	$.cookie('browser_warning_close', 1, {expires: 14, path: Drupal.basePath});
	
	$(a).parent().remove();
}