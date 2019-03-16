m, n = [int(i) for i in input().split()]

k = int(input())

a = []
for i in range(n):
	a.append([None] * m)
	for j in range(m):
		a[i][j] = '0'

for i in range(k):
	xmin, ymin, xmax, ymax = [int(i)-1 for i in input().split()]
	for p in range(ymin, ymax + 1):
		a[p][xmin] = '1'
		a[p][xmax] = '1'
	for q in range(xmin, xmax + 1):
		a[ymin][q] = '1'
		a[ymax][q] = '1'

for i in range(n):
	for j in range(m):
		print(a[i][j], sep = '', end = '')
	print()
