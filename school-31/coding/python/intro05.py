k, n, q = [int(i) for i in input().split()]

def pal(x, n):
	x1 = str(x)
	while len(x1) < n:
		x1 = '0' + x1
	x2 = x1[::-1]
	return x1 == x2

m = 0
for x in range(0, 10 ** n, q):
	if pal(x, n):
		m += 1

s = (26 ** k) * (10 ** n) - 26 * (10 ** n) + 26 * m

print(s)