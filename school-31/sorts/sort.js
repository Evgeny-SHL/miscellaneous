'use strcit';

function quickSort(a) {

	var
		l = 0,
		r = a.length - 1;
	sorting(a, l, r);

	function sorting(a, l, r) {

		var
			m = a[Math.floor((l + r) / 2)],
			i = l,
			j = r;

		do {
			while (a[i] < m)
				i++;
			while (a[j] > m)
				j--;
			if (i <= j) {
				var swap = a[i];
				a[i] = a[j];
				a[j] = swap;
				i++;
				j--;
			}
		} while (i <= j);

		if (l < j) sorting(a, l, j);
		if (i < r) sorting(a, i, r);
	};
}

function bubbleSort(a) {

	for (var i = 0; i < a.length - 1; i++)
		for (var j = 0; j < a.length - i - 1; j++)
			if (a[j] > a[j+1]) {
				var swap = a[j];
				a[j] = a[j+1];
				a[j+1] = swap;
			}
}

function selectionSort(a) {

	for (var i = 0; i < a.length - 1; i++) {
		var m = i;
		for (var j = i + 1; j < a.length - 1; j++)
			m = a[j] < a[m] ? j : m;
		var swap = a[i];
		a[i] = a[m];
		a[m] = swap;
	}
}

function countingSort(a) {

	var b = new Array(a.length);
	for (var i = 0; i < a.length; i++)
		b[i] = 0;

	for (var i = 0; i < a.length; i++)
		b[a[i]]++;

	var
		c = [],
		k = 0;
	for (var i = 0; i < a.length; i++)
		for (var j = 0; j < b[i]; j++) {
			c[k] = i;
			k++;
		}

	for (var i = 0; i < a.length; i++)
		a[i] = c[i];
}

function mergeSort(a) {

	a = sorting(a, 0, a.length);

	function sorting(a, start, finish) {

		var
			mid = Math.floor((start + finish) / 2);
		var
			b = [],
			c = [];
		if (mid - start > 1)
			b = sorting(a, start, mid);
		else
			b[0] = a[start];
		if (finish - mid > 1)
			c = sorting(a, mid, finish);
		else
			c[0] = a[mid];

		var
			i = 0,
			j = 0;
		b.push(Infinity);
		c.push(Infinity);
		while ((i < b.length - 1) || (j < c.length - 1)) {
			if (b[i] <= c[j]) {
				a[start+i+j] = b[i];
				i++;
			} else {
				a[start+i+j] = c[j];
				j++;
			}
		}

		var d = [];
		for (var i = start; i < finish; i++)
			d[i-start] = a[i];
		return d;
	}
}

function insertionSort(a) {

	for (var i = 0; i < a.length; i++) {
		var x = a[i];
		for (var j = i-1; (a[j] > x) && (j >= 0); j--)
			a[j+1] = a[j];
		a[j+1] = x;
	}
}

function shellSort(a) {

	var inc = [1],
		k = 0;
	while (3*inc[k] < a.length) {
		k++;
		if (k % 2 == 0)
			inc[k] = 9 * Math.pow(2, k) - 9 * Math.pow(2, Math.round(k / 2)) + 1;
		else
			inc[k] = 8 * Math.pow(2, k) - 6 * Math.pow(2, Math.round((k+1) / 2)) + 1;
	}
	k = k > 0 ? k-- : 0;

	while (k >= 0) {
		var t = inc[k--];
		for (var i = t; i < a.length; i++) {
			x = a[i];
			for (var j = i - t; (a[j] > x) && (j >= 0); j -= t)
				a[j+t] = a[j];
			a[j+t] = x;
		}
	}
}

function heapSort(a) {
	var heap = new Heap();
	for (var i = 0; i < a.length; i++)
		heap.add(a[i]);
	for (var i = 0; i < a.length; i++)
		a[i] = heap.extractMin();
}

var
	a = [],
	b = [],
	c = [],
	d = [],
	e = [],
	f = [],
	g = [],
	h = [];
var t = [];
t[0] = [];
for (var n = 10; n <= 5000; n += 10) {
	for (var i = 0; i < n; i++) {
		a[i] = Math.round(Math.random() * n - 0.5);
	//	b[i] = c[i] = d[i] = e[i] = f[i] = g[h] = h[i] = a[i];
	}

	//1
	var date = new Date();
	bubbleSort(a);
	t[0].push(new Date() - date);
	/*var date = new Date();
	//2
	bubbleSort(b);
	t.push(new Date() - date);
	//3
	var date = new Date();
	countingSort(c);
	t.push(new Date() - date);
	//4
	var date = new Date();
	selectionSort(d);
	t.push(new Date() - date);
	//5
	var date = new Date();
	mergeSort(e);
	t.push(new Date() - date);
	//6
	var date = new Date();
	shellSort(g);
	t.push(new Date() - date);
	//7
	var date = new Date();
	heapSort(h);
	t.push(new Date() - date);
	//8
	var date = new Date();
	insertionSort(f);
	t.push(new Date() - date);*/

	//console.log(n,t);
}