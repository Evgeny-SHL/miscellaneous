par = []

for i in range(1, 101):
	if 100 % i == 0:
		par.append(i)
par += [100 * i for i in par] + [100 * 100 * i for i in par]

# print(par)

s = 99999999
k = 0
s1 = s
while s1 > 0:
	i = len(par) - 1
	while par[i] > s1:
		i -= 1
	s1 -= par[i]
	k += 1
print('Сумма:', s, 'Всего монет:', k)