function getRandomColor() {
  var letters = '0123456789ABCDEF';
  var color = '#';
  for (var i = 0; i < 6; i++) {
    color += letters[Math.floor(Math.random() * 16)];
  }
  return color;
}

function work()
{
	var canvas = document.getElementById('canvas');
	var ctx = canvas.getContext('2d');
	var raf;
	var ball = {
	  x: 100,
	  y: 100,
	  vx: 5,
	  vy: 5,
	  radius: 100,
		color: getRandomColor(),
	  draw: function() {
		ctx.beginPath();
		ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2, true);
		ctx.closePath();
		ctx.fillStyle = this.color;
		ctx.fill();
	  }
	};

	function draw() {
	  ctx.clearRect(0,0, canvas.width, canvas.height);
	  ball.draw();
	  ball.x += ball.vx;
	  ball.y += ball.vy;

	  if (ball.y + ball.vy > canvas.height ||
		  ball.y + ball.vy < 0) {
		ball.vy = -ball.vy;
	  }
	  if (ball.x + ball.vx > canvas.width ||
		  ball.x + ball.vx < 0) {
		ball.vx = -ball.vx;
	  }
		
	  raf = window.requestAnimationFrame(draw);
	}

	canvas.addEventListener('mouseover', function(e) {
	  raf = window.requestAnimationFrame(draw);
	});

	canvas.addEventListener('mouseout', function(e) {
  window.cancelAnimationFrame(raf);
	});

	canvas.addEventListener('click', function(e) {			
		document.getElementById("demo").innerHTML = ball.x - ball.radius
;	
		if((Math.abs(ball.x - e.x) < ball.radius) && (Math.abs(ball.y - e.y) < ball.radius))    
		{
			ball.color = getRandomColor();
			ball.radius /= 1.2;
			points++;
		}	
	});


	ball.draw();
}
