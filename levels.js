
var level1 = Array();
level1[0] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 1];
level1[1] = [1, 0, 1, 1, 1, 1, 0, 1, 0, 1];
level1[2] = [1, 1, 0, 1, 1, 0, 1, 1, 0, 1];
level1[3] = [1, 1, 1, 0, 0, 1, 1, 1, 0, 1];
level1[4] = [1, 1, 1, 0, 0, 1, 1, 1, 0, 1];
level1[5] = [1, 1, 0, 1, 1, 0, 1, 1, 0, 1];
level1[6] = [1, 1, 1, 1, 1, 1, 0, 1, 0, 1];
level1[7] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 1];
level1[8] = [1, 0, 1, 0, 1, 0, 1, 1, 0, 1];
level1[9] = [1, 0, 1, 0, 1, 0, 1, 1, 0, 1];

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
	Console("Loading level");

	this.blocks = new Array();
	this.LoadLevel = function() {
	
		for(var y = 0; y < 10; y++) {
		
			for(var x = 0; x < 10; x++) {
			
				if( level1[x][y] != undefined && level1[x][y] != 0 ) {
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
			
			var theBlock = this.blocks[block];
			
			if( theBlock.alive == false ) continue;
		
			if( !CheckCollide(theBlock, Ball) )
				continue;
			
			// if we make it this far the ball should be colliding with a block
			Bat.score += this.blocks[block].score;			
			this.blocks[block].alive = false;
			
			Ball.speedy *= -1;
		}
	}
}
