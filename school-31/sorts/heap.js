function Heap() {
	this.value = [];

	this.siftUp = function(k) {
		var h = this.value;
		while (k != 0) {
			var p = Math.floor((k - 1) / 2);
			if (h[p] > h[k]) {
				var swap = h[p];
				h[p] = h[k];
				h[k] = swap;
			}
			k = p;
		}
	}



	this.add = function(x) {
		var h = this.value;
		h.push(x);
		this.siftUp(h.length-1);
	}

	this.siftDown = function(k) {
		var h = this.value;
		while (2*k + 1 < h.length) {
			var p = 2*k + 1;
			if ((p + 1 < h.length) && (h[p+1] < h[p]))
				p++;
			if (h[p] < h[k]) {
				var swap = h[p];
				h[p] = h[k];
				h[k] = swap;
			}
			k = p;
		}
	}

	this.extractMin = function() {
		var h = this.value;
		x = h[0];
		var swap = h[0];
		h[0] = h[h.length-1];
		h[h.length-1] = h[0];
		h.pop();
		this.siftDown(0);
		return x;
	}
}