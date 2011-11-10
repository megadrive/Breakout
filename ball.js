
// the ball
var Ball = {
	width: 8,
	height: 8,
	
	posx: 0,
	posy: 0,
	
	speedbase: 154,
	speedx: 0,
	speedy: 0,
	
	image: null,
	
	Init: function() {
		this.posx = canvas.width / 2;
		this.posy = canvas.height / 2;
		
		this.speedx = Math.floor(Math.random() * 154);
		this.speedy = Math.floor(Math.random() * 154);
		
		if( Math.floor(Math.random() * 2) == 0 ) this.speedx *= -1;
		if( Math.floor(Math.random() * 2) == 0 ) this.speedy *= -1;
	},
	
	Move: function() {
		this.posx = this.posx + (this.speedx * FPSS);
		this.posy = this.posy + (this.speedy * FPSS);
		
		if( this.posx < this.width / 2 ) this.speedx *= -1;
		if( this.posx + this.width / 2 > canvas.width ) this.speedx *= -1;
		if( this.posy < 0 ) this.speedy *= -1;
	},
	
	Draw: function() {
		ctx.drawImage(this.image, this.posx - (this.width / 2), this.posy - (this.height / 2));
	}
}
