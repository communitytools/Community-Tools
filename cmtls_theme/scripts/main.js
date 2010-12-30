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


/* Toggle Profile Section */
jQuery(document).ready(function(){

	jQuery(".profile-section-container").show();

	jQuery(".profile-section-toggle-button").toggle(function(){
		jQuery(this).addClass("active"); 
		}, function () {
		jQuery(this).removeClass("active");
	});

	jQuery(".profile-section-toggle-button").click(function(){
		jQuery(this).next(".profile-section-container").slideToggle("slow,");
	});

});

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

/* ÑÑÑÑÑ DROP-DOWN ÑÑÑÑÑ */
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