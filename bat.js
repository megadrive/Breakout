
// the bat
var Bat = {	
	width: 30,
	height: 8,
	
	lives: 3,
	score: 0,
	
	posx: 0,
	posy: 0,
	
	image: null,
	
	holdingBall: true,
	
	Init: function() {
		this.posy = canvas.height - 30;
	},
	
	// methods
	Move: function(event) {
		Bat.posx = event.x;
	},
	
	Draw: function(ctx) {
		ctx.drawImage(this.image, this.posx - (this.width / 2), this.posy);
	}
}
