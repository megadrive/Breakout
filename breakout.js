
function Console(msg) {
	$("#console").prepend("<div class=\"consoleMessage=\">" + msg + "</div>");
}

var ctx = null;
var current_level = 0;
var level = null;

$(document).ready( function() {
	// hide the preloaded images
	$("#preload").hide();
	
	// we should have our consts at this point
	$("#screen").css(
		{
			"border": "1px dashed #ff00ff",
			"background-color": "#111"
		}
	);
	
	// initialise input using jquery tappy (http://github.com/Xion/jQuery.Tappy)
	$("#screen").tappy();
	$("#screen").bind('move.tappy', HandleInput);
	
	// get the context and canvas
	canvas = $("#screen")[0];
	ctx = canvas.getContext("2d");
	
	// define the bat's image
	Bat.image = $("#imgBat")[0];
	Ball.image = $("#imgBall")[0];
	
	Bat.Init();
	Ball.Init();
	
	Console(level1);
	level = new Level(level1);
	level.LoadLevel(0);

	setInterval(Update, FPSMS);
} );

function HandleInput(event) {
	Bat.Move(event);
}

function Update() {
	ctx.clearRect(0,0, canvas.width, canvas.height);
	
	level.Collisions();
	
	Ball.Move();
	
	Render();
}

function Render() {
	Bat.Draw(ctx);
	Ball.Draw(ctx);
	
	level.Draw(ctx);
}

function CheckCollide(obj, obj2) {
	if( obj.posx                  > obj2.posx + obj2.width ) return false;
	if( obj.posx + obj.width      < obj2.posx              ) return false;

	if( obj.posy                  > obj2.posy + obj2.height ) return false;
	if( obj.posy + obj.height     < obj2.posy               ) return false;
	
	return true;
}
