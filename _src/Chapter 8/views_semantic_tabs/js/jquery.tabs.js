(function($){
	$.fn.tabs = function() {
		this.each(function() {
			var el = $(this);
			var current;
			
			el.addClass('enhance');
			var dlHeight = el.height();

			el.find('dd').hide();
			
			var hash = location.hash;
			
			if (el.find('dt a[href="'+hash+'"]').length) {
				current = el.find('a[href="'+hash+'"]').parent().addClass('current');
				var dd = el.find('a[href="'+hash+'"]').parent().next('dd');
			} else {
			  var dd = el.find('dd:first');
        current = el.find('dt:first').addClass('current');
			}
      //get padding with borders
      var wPadding = dd.outerWidth() - dd.width();
      dd.width(el.width()-wPadding);
			
			var currentHeight = current.next('dd').show().height();
			el.css('height', dlHeight + currentHeight);
		});


		$('dl.enhance dt a').click(function(e){
			e.preventDefault();
			
			var dl = $(this).parents('dl');

			dl.find('.current').removeClass('current').next('dd').hide();
			var current = $(this).parent('dt').addClass('current');

      var dd = current.next('dd');
      //get padding with borders
      var wPadding = dd.outerWidth() - dd.width();
      dd.width(dl.width()-wPadding);
			
			var currentHeight = current.next('dd').show().height();
			var dlHeight = dl.removeAttr('style').height();
			
			dl.css('height', dlHeight + currentHeight);
			
			location.hash = $(this).attr('href');
		});
	}
})(jQuery);