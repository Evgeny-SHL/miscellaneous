inp = open('sight.in')
outp = open('sight.out', 'w')

n, r = [int(i) for i in inp.readline().split()]
coord = [None] * n
k = 0

for i in range(n):
	coord[i] = [int(j) for j in inp.readline().split()]
	for j in range(i):
		a = coord[j][1] - coord[i][1]
	#	b = coord[i][0] - coord[j][0]
		c = coord[i][1] * (coord[j][0] - coord[i][0]) - coord[i][0] * (coord[j][1] - coord[i][1])
		if (r ** 2) * (c ** 2) < (a ** 2) * (c ** 2):
			k += 1

print(k, file = outp)