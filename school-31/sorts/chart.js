function chart(minN, minTime, maxN, maxTime, inc) {
	console.log(t[0]);
	var graph = document.getElementById('graph');
	graph.width = graph.width;
	if (!graph.getContext) return;
	var g = graph.getContext('2d');
	var
		width = graph.width,
		height = graph.height;

	function funcToY(y) { return height - height * (y - minTime) / (maxTime - minTime); }
	function argToX(x) { return width * (x - minN) / (maxN - minN); }

	var equity = 0;
	g.beginPath();
	g.moveTo(0, height);
	g.lineTo(argToX(minN), funcToY(minTime));
	for (var n = minN; n <= maxN; n += inc) {
		g.lineTo(argToX(n), funcToY(t[0][Math.floor(n/20)-1]));
	}
	g.lineTo(argToX(maxN), height);
	g.closePath();
//	g.fillStyle = 'aaf';
//	g.fill();
	g.lineWidth = 2;
	g.stroke();

	/*g.fillStyle = 'black';
	g.fillRect(0, height/2-0.5, width, 1);
	g.fillRect(width/2-0.5, 0, 1, height);
	g.textAlign = 'left';
	for (var i = minx + 1; i < maxx; i++) {
		var x = argToX(i);
		g.fillRect(x-0.5, height/2-3, 1, 6);
		if (i == minx + 1) g.fillText('   Argument', x, height/2-6);
			else if (!(i % 10)) g.fillText(' ' + i, x, height/2-6);
	}


	for (var i = miny + 1; i < maxy; i++) {
		var y = funcToY(i);
		g.fillRect(width/2-3, y-0,5, 1, 6);
		if (i == miny + 1) g.fillText('   Function', width/2, y);
			else if (!(i % 10) && i) g.fillText(' ' + i, width/2, y);
	}*/
}

chart(10, 0, 5000, 50, 10);