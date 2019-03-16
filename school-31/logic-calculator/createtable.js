'use strict';

submit.onsubmit = function() {								// Действия при клике на кнопку.
	var
		button = document.getElementById('create'),			// Кнопка
		form = document.getElementById('formula'),			// текствовое поле,
		result = document.getElementById('result'),			// Получить контейнер для результатов,
		tTable = document.getElementById('tTable'),			// таблицу истинности и
		error = document.getElementById('error');			// сообщение об ощибке.

	if (tTable) {									// Если уже есть таблица истинности,
		result.removeChild(tTable);					// то стереть ее.
	}
	if (error) {									// Если есть сообщение об ошибке,
		result.removeChild(error);					// то стереть его.
	}

	var vars = [],										// Массив переменных,
		formula = standartFormula(form.value);			// и введенная формула в стандартном виде.

	var checker = checkFormula(formula);						// Объект прерки формулы.
	if (!checker.valid) {										// Если формула некорректна,
		var error = document.createElement('span');				// то создать сообщение об ошибке,
		error.id = 'error';										// присвоить ему идентификатор
		result.appendChild(error).innerHTML = checker.error;	// отобразить сообщение и
		return false;													// выйти из функции — далее ничего не делать.
	}

	console.log(difficult(formula));

	for (var i = 0; i < formula.length; i++) {							// Цикл по символам формулы.
		var s = formula.charAt(i);										// Получаем символ формулы;

		if ((varSymbols.indexOf(s) != -1) && (vars.indexOf(s) == -1))	// если символа в списке допустимых символов и нет в массиве переменных,
			vars.push(s);												// то добавить его в массив переменных.
	}

	vars.sort();									// Сортируем массив переменных по возрастанию.
	var n = vars.length;							// Сохраняем количество переменных.

	tTable = document.createElement('table');						// Создаем таблицу истинности,
	tTable.id = 'tTable';											// присваиваем е идентификатор.
	tTable.appendChild(document.createElement('tr'));				// Добавляем в таблицу строку.
	for (i = 0; i < n+1; i++) {										// Цикл от нуля до количества переменных + 1:
		tTable.rows[0].appendChild(document.createElement('th'));	// создаем заголовчную ячейку
		if (i < n) tTable.rows[0].cells[i].innerHTML = vars[i];		// и, если есть переменная, то записать ее в ячейку.
	}
	tTable.rows[0].cells[i-1].innerHTML = formula;					// В последнюю ячейку запишем саму формулу.

	for (i = 0; i < Math.pow(2, n); i++) {										// Берем числа от нуля до 2^n-1
		var code = i.toString(2);												// и переводим их в двоичную систему,
		while (code.length < n)
			code = '0' + code;													// дописывая в начало нули при необходимости.

		var f = countValue(formula, code, vars);								// Получаем значение формулы для данного набора переменных.

		tTable.appendChild(document.createElement('tr'));						// Дописываем в таблицу еще одну строку,
		for (var j = 0; j < n+1; j++) {
			tTable.rows[i+1].appendChild(document.createElement('td'));			// где также создаем ячейки
			if (j < n) tTable.rows[i+1].cells[j].innerHTML = code.charAt(j);	// и заполняем их значениями переменной.
		}
		tTable.rows[i+1].cells[j-1].innerHTML = f;								// В последнец ячейке будет значение формулы.
	}

	result.appendChild(tTable);						// Рисуем таблицу.
	return false;
}