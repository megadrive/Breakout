
var level1 =
[
	[0,0], [0,0], [0,0], [1,1], [1,1],
	[0,1], [1,1], [1,1], [1,0], [0,1],
	[0,1], [1,1], [1,1], [1,1], [1,1],
	[0,1], [1,1], [1,1], [1,1], [1,0],
	[0,0], [0,0], [0,0], [1,1], [1,1]
];

var levels = [level1];

// block
var Block = function(posx, posy, score) {
	this.posx = posx;
	this.posy = posy;
	
	this.width = 32;
	this.height = 8;
	
	this.score = score;
	
	this.alive = true;
	
	this.image = null;
}

// level, comprised of blocks
var Level = function(blockArray) {
	this.blocks = new Array();
	this.LoadLevel = function() {
	
		for(var y = 0; y < 5; ++y) {
		
			for(var x = 0; x < 5; ++x) {
			
				if( level1[x][y] != 0 ) {
					this.blocks[this.numBlocks] = new Block(x, y, 10);
					this.blocks[this.numBlocks].posx *= this.blocks[this.numBlocks].width + 3;
					this.blocks[this.numBlocks].posy *= this.blocks[this.numBlocks].height + 3;
					this.blocks[this.numBlocks].image = $("#imgBat")[0];
					this.numBlocks++;
				}
			}
		}
	}
	
	this.numBlocks = 0;
	
	this.Draw = function(ctx) {
		for(var block = 0; block < this.numBlocks; ++block) {
			if( this.blocks[block].alive ) {
				ctx.drawImage( this.blocks[block].image, this.blocks[block].posx, this.blocks[block].posy );
			}
		}
	}
	
	this.Collisions = function() {
		for(var block = 0; block < this.numBlocks; ++block) {
			//continue; // test
			
			var theBlock = this.blocks[block];
			
			if( theBlock.alive == false ) continue;
		
			if( theBlock.posx - theBlock.width / 2 > Ball.posx + Ball.width / 2 ) continue;
			if( theBlock.posx + theBlock.width / 2 < Ball.posx - Ball.width / 2) continue;
		
			if( theBlock.posy - theBlock.height / 2 > Ball.posy + Ball.height / 2 ) continue;
			if( theBlock.posy + theBlock.height / 2 < Ball.posy - Ball.height / 2) continue;
			
			// // work out where it was hitting from and modify the ball trajectory accordingly			
			var diffx = Ball.posx - this.blocks[block].posx;
			var diffy = Ball.posy - this.blocks[block].posy;
			var length = (diffx * diffx) + (diffy * diffy);
			var diffxnorm = diffx / length;
			var diffynorm = diffy / length;
			
			if( diffxnorm > 0.2 )
				Ball.speedx = Ball.speedx * -diffxnorm;
			if( diffxnorm > 0.2 )
				Ball.speedy = Ball.speedy * -diffynorm;
			
			// if we make it this far the ball should be colliding with a block
			Bat.score += this.blocks[block].score;			
			this.blocks[block].alive = false;
		}
	}
}
