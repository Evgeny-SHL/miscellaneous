'use strict';

var
	add = document.getElementById('add'),
	del = document.getElementById('del'),
	form = document.getElementsByClassName('premise'),			// текствовое поле,
	formulas = document.getElementById('formulas');

add.onclick = function() {
	if (form.length >= 10) {
		return false;
	}
	var input = document.createElement('input');
	input.type = 'text';
	input.className = 'premise';
	submit.appendChild(input);
	formulas.appendChild(document.createElement('br'));
	formulas.appendChild(input);
	return false;
}

del.onclick = function() {
	if (form.length < 2) {
		return false;
	}
	var
		br = formulas.getElementsByTagName('br'),
		f = formulas.getElementsByClassName('premise');
	formulas.removeChild(br[br.length-1]);
	formulas.removeChild(f[f.length-1]);
	return false;
}

submit.onsubmit = function() {								// Действия при клике на кнопку.
	var
		button = document.getElementById('check'),
		result = document.getElementById('result'),			// Получить контейнер для результатов,
		message = document.getElementById('message'),		// сообщение об ощибке.
		error = document.getElementById('error'),
		conclusion = document.getElementById('conclusion');

	if (message) {									// Если есть сообщение об ошибке,
		result.removeChild(message);					// то стереть его.
	}
	if (error) {									// Если есть сообщение об ошибке,
		result.removeChild(error);					// то стереть его.
	}

	var vars = [],										// Массив переменных,
		formula_1 = '',			// и введенная формула в стандартном виде.
		formula_2 = standartFormula(conclusion.value);

	for (var i = 0; i < form.length-1; i++) {
		var checker = checkFormula(standartFormula(form[i].value));
		if (!checker.valid) {										// Если формула некорректна,
			var error = document.createElement('span');				// то создать сообщение об ошибке,
			error.id = 'error';										// присвоить ему идентификатор
			result.appendChild(error).innerHTML = checker.error;	// отобразить сообщение и
			return false;											// выйти из функции — далее ничего не делать.
		}
		formula_1 += '(' + form[i].value + ')∧';
	}
	formula_1 += '(' + form[form.length-1].value + ')';
	formula_1 = standartFormula(formula_1);

	var checker = checkFormula(standartFormula(form[form.length-1].value));		// Объект прерки формулы.
	if (!checker.valid) {										// Если формула некорректна,
		var error = document.createElement('span');				// то создать сообщение об ошибке,
		error.id = 'error';										// присвоить ему идентификатор
		result.appendChild(error).innerHTML = checker.error;	// отобразить сообщение и
		return false;											// выйти из функции — далее ничего не делать.
	}
	var checker = checkFormula(formula_1);						// Объект прерки формулы.
	if (!checker.valid) {										// Если формула некорректна,
		var error = document.createElement('span');				// то создать сообщение об ошибке,
		error.id = 'error';										// присвоить ему идентификатор
		result.appendChild(error).innerHTML = checker.error;	// отобразить сообщение и
		return false;											// выйти из функции — далее ничего не делать.
	}
	var checker = checkFormula(standartFormula(formula_2));		// Объект прерки формулы.
	if (!checker.valid) {										// Если формула некорректна,
		var error = document.createElement('span');				// то создать сообщение об ошибке,
		error.id = 'error';										// присвоить ему идентификатор
		result.appendChild(error).innerHTML = checker.error;	// отобразить сообщение и
		return false;											// выйти из функции — далее ничего не делать.
	}

	for (var i = 0; i < formula_1.length; i++) {							// Цикл по символам формулы.
		var s = formula_1.charAt(i);										// Получаем символ формулы;

		if ((varSymbols.indexOf(s) != -1) && (vars.indexOf(s) == -1))	// если символа в списке допустимых символов и нет в массиве переменных,
			vars.push(s);												// то добавить его в массив переменных.
	}
	for (var i = 0; i < formula_2.length; i++) {
		var s = formula_2.charAt(i);

		if ((varSymbols.indexOf(s) != -1) && (vars.indexOf(s) == -1))	// если символа в списке допустимых символов и нет в массиве переменных,
			vars.push(s);
	}

	vars.sort();									// Сортируем массив переменных по возрастанию.
	var n = vars.length;							// Сохраняем количество переменных.

	var message = document.createElement('span');
	message.id = 'message';

	for (i = 0; i < Math.pow(2, n); i++) {										// Берем числа от нуля до 2^n-1
		var code = i.toString(2);												// и переводим их в двоичную систему,
		while (code.length < n)
			code = '0' + code;													// дописывая в начало нули при необходимости.

		var f1 = countValue(formula_1, code, vars);								// Получаем значение формулы для данного набора переменных.
		var f2 = countValue(formula_2, code, vars);
		if (!(!f1 || f2)) {
			var str = 'Аргумент неправильный: из конъюнкции посылок не следует заключение: при наборе переменных ' ;
			for (var j = 0; j < n-1; j++) {
				str += vars[j] + '≡' + code[j] + ', ';
			}
			str += vars[n-1] + '≡' + code[n-1] + ' импликация антецедента — конъюнкции посылок и консеквента-заключения ложна.'
			message.className = "minus";
			result.appendChild(message).innerHTML = str;
			return false;
		}
	}

	message.className = "plus";
	result.appendChild(message).innerHTML = 'Аргумент правильный.';
	return false;
}