'use strict';

submit.onsubmit = function() {								// Действия при клике на кнопку.
	var
		button = document.getElementById('check'),					// Кнопка
		form_1 = document.getElementById('formula_1'),					// текствовое поле,
		form_2 = document.getElementById('formula_2'),
		result = document.getElementById('result'),			// Получить контейнер для результатов,
		message = document.getElementById('message'),		// сообщение об ощибке.
		error = document.getElementById('error');

	if (message) {									// Если есть сообщение об ошибке,
		result.removeChild(message);					// то стереть его.
	}
	if (error) {									// Если есть сообщение об ошибке,
		result.removeChild(error);					// то стереть его.
	}

	var vars = [],										// Массив переменных,
		formula_1 = standartFormula(form_1.value),			// и введенная формула в стандартном виде.
		formula_2 = standartFormula(form_2.value);

	var checker = checkFormula(formula_1);						// Объект прерки формулы.
	if (!checker.valid) {										// Если формула некорректна,
		var error = document.createElement('span');				// то создать сообщение об ошибке,
		error.id = 'error';										// присвоить ему идентификатор
		result.appendChild(error).innerHTML = checker.error;	// отобразить сообщение и
		return false;											// выйти из функции — далее ничего не делать.
	}
	var checker = checkFormula(formula_2);						// Объект прерки формулы.
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
			var str = 'Из первой формулы не следует вторая: при наборе переменных ';
			for (var j = 0; j < n-1; j++) {
				str += vars[j] + '≡' + code[j] + ', ';
			}
			str += vars[n-1] + '≡' + code[n-1] + ' импликация формул ложна.'
			message.className = "minus";
			result.appendChild(message).innerHTML = str;
			return false;
		}
	}

	message.className = "plus";
	result.appendChild(message).innerHTML = 'Из первой формулы следует вторая: ' + formula_1 + '⇒' + formula_2 + '.';
	return false;
}