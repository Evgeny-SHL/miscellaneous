'use strict';

var
	result = document.getElementById('result'),
	add = document.getElementById('add'),
	del = document.getElementById('del'),
	tTable = document.getElementById('tTable').getElementsByTagName('tbody')[0];			// текствовое поле,

add.onclick = function() {
	var t = tTable;
	if (t.rows.length >= 32) return false;
	t.rows[0].cells[t.rows[0].cells.length-1].insertAdjacentElement('beforebegin', document.createElement('th'));
	t.rows[0].cells[t.rows[0].cells.length-2].innerHTML = String.fromCharCode(t.rows[0].cells[t.rows[0].cells.length-3].innerHTML.charCodeAt(0)+1);
	for (var i = 1; i < t.rows.length; i++) {
		t.rows[i].appendChild(document.createElement('td'));
	}
	var tr = [];
	for (var i = 0; i < t.rows.length-1; i++) {
		tr[i] = document.createElement('tr');
		for (var j = 0; j < t.rows[0].cells.length; j++) {
			tr[i].appendChild(document.createElement('td'));
		}
	}
	for (var i = 0; i < tr.length; i++)
		t.appendChild(tr[i]);
	var n = t.rows[0].cells.length-1;
	for (var i = 0; i < Math.pow(2, n); i++) {
		var code = i.toString(2);
		while (code.length < n)
			code = '0' + code;
		for (var j = 0; j < n; j++)
			t.rows[i+1].cells[j].innerHTML = '' + code.charAt(j);
		var res = document.createElement('input');
		res.type = 'text';
		res.className = 'res';
		t.rows[i+1].cells[j].appendChild(res);
	}
	result.replaceChild(tTable, t);
	return false;
}

del.onclick = function() {
	var t = tTable;
	if (t.rows.length<=3) return false;
	for (var i = 0; i < t.rows.length; i++)
		t.rows[i].removeChild(t.rows[i].cells[0]);
	for (var i = 0; i < t.rows[0].cells.length-1; i++) {
		t.rows[0].cells[i].innerHTML = String.fromCharCode(t.rows[0].cells[i].innerHTML.charCodeAt(0)-1);
	}
	while (t.rows.length > Math.pow(2, t.rows[0].cells.length-1)+1)
		t.removeChild(t.rows[t.rows.length-1]);
	result.replaceChild(tTable, t);
	return false;
}

submit.onsubmit = function() {								// Действия при клике на кнопку.
	var
		button = document.getElementById('create'),
		reses = document.getElementsByClassName('res'),
		message = document.getElementById('message'),
		error = document.getElementById('error');

	if (message) {
		result.removeChild(message);
	}
	if (error) {
		result.removeChild(error);
	}

	var s = 0;
	for (var i = 0; i < reses.length; i++) {
		s += reses[i].value == '1' ? 1 : 0;
		if (reses[i].value != '1' && reses[i].value != '0') {
			var error = document.createElement('span');
			error.id = 'error';
			var str = reses[i].value == '' ? 'Пустая формула.' : 'Недопустимый символ.';
			result.appendChild(error).innerHTML = str;
			return false;
		}
	}

	var f;
	if (s == 0) f = false;
	if (s == reses.length) f = true;
	var message = document.createElement('span');
	message.id = 'message';
	var span = document.createElement('span');
	if (f === true || f === undefined) {
		var g = '';

		for (var i = 0; i < reses.length; i++) {
			if (reses[i].value == '0') continue;
					for (var j = 0; j < tTable.rows[0].cells.length-1; j++) {
				if (tTable.rows[i+1].cells[j].innerHTML == '1') {
					g += tTable.rows[0].cells[j].innerHTML + '∧';
				} else {
					g += '¬' + tTable.rows[0].cells[j].innerHTML + '∧';
				}
			}
			g = g.slice(0, g.length-1);
			g += '∨';

		}
		g = g.slice(0, g.length-1);
		span.className = 'plus';
		result.appendChild(message).appendChild(span).innerHTML = 'Совершенная дизъюнктивная нормальная форма: F≡' + g + '.';
	} else {
		span.className = 'minus';
		result.appendChild(message).appendChild(span).innerHTML = 'Совершенной дизъюнктивной нормальной формы F не существует.';
	}
	var span = document.createElement('span');
	if (f === false || f === undefined) {
		var g = '';
		for (var i = 0; i < reses.length; i++) {
			
			if (reses[i].value == '1') continue;
			g = g + '(';
			for (var j = 0; j < tTable.rows[0].cells.length-1; j++) {
				if (tTable.rows[i+1].cells[j].innerHTML == '0') {
					g += tTable.rows[0].cells[j].innerHTML + '∨';
				} else {
					g += '¬' + tTable.rows[0].cells[j].innerHTML + '∨';
				}
			}
			g = g.slice(0, g.length-1);
			g = g + ')∧';
		}
		g = g.slice(0, g.length-1);
		span.className = 'plus';
		result.appendChild(message).appendChild(span).innerHTML = '<br>Совершенная конъюнктивная нормальная форма: F≡' + g + '.';
	} else {
		span.className = 'minus';
		result.appendChild(message).appendChild(span).innerHTML = '<br>Совершенной конъюнктивной нормальной формы F не существует.';
	}
	return false;
}