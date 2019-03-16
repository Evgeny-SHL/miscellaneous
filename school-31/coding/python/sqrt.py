n = float(input('Число:'))
e = int(input('Число надежных знаков после запятой:'))

m = int(n) # Число, которое можно менять.
group = 1 # Число групп до запятой.
ans1 = '' # Целая часть ответа.

# # # # # Обработка целой части числа.
while 10 ** (2 * group) < m:
	group += 1

med = m // (10 ** (2 * group - 2)) # Первая группа числа.
dig = 0 # Будущее минимальное число x: x*x <= med.
while dig ** 2 <= med:
	dig += 1
dig -= 1
ans1 = str(dig) # Приписали к ответу первую цифру.
group -= 1 # Обработали одну группу
m = m % (10 ** (2 * group)) # и убрали ее.

num = dig ** 2 # Для вычисления разницы возведем в квадрат.
delta = 0
while group > 0:
	delta = med - num # Разница.
	med = 100 * delta + m // (10 ** (2 * group - 2)) # Новая обрабатываемая группа.
	num = 20 * int(ans1) # Ищем число.
	dig = 0 # Ищем его последнюю цифру.
	while (num + dig) * dig <= med:
		dig += 1
	dig -= 1
	num = (num + dig) * dig
	ans1 += str(dig) # Дописали к целой части еще одну цифру.
	group -= 1 # Обработали одну группу
	m = m % (10 ** (2 * group)) # и убрали ее.

# # # # # Обработка дробной части числа.
m = str(n)[str(n).index('.')+1:]
while len(m) < 2 * e:
	m += '0'
m = int(m)
ans2 = '' # Дробная часть числа
ans3 = ans1 # Итоговое число без десятичного разделителя.

group = e
delta = med - num
med = 100 * delta + m // (10 ** (2 * group - 2))
print(delta, med)
num = 20 * int(ans1)
dig = 0
while (num + dig) * dig <= med:
	dig += 1
dig -= 1
num = (num + dig) * dig
ans2 = str(dig) # Приписали к ответу первую цифру.
ans3 = ans1 + ans2
group -= 1 # Обработали одну группу
m = m % (10 ** (2 * group)) # и убрали ее.

while group > 0:
	delta = med - num # Разница.
	med = 100 * delta + m // (10 ** (2 * group - 2)) # Новая обрабатываемая группа.
	num = 20 * int(ans3) # Ищем число.
	dig = 0 # Ищем его последнюю цифру.
	while (num + dig) * dig <= med:
		dig += 1
	dig -= 1
	num = (num + dig) * dig
	ans2 += str(dig) # Дописали к дробной части еще одну цифру.
	ans3 = ans1 + ans2 # Дописали к ответу без разделителя еще одну цифру.
	group -= 1
	m = m % (10 ** (2 * group)) # и убрали ее.

answer = ans1 + '.' + ans2

print(answer)