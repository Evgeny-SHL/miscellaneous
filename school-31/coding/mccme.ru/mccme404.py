n, m = [int(i) for i in input().split()]

def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

k = 0
if n == 1:
	print(m)
elif n == m:
	print(m)
elif (m-1) % (n-1) == 0:
	l = (m-1) // (n-1)
	for i in range(n):
		j = i * l
		if 0 <= j < m:
			k += 1
	print(k)
elif (n-1) % (m-1) == 0:
	l = (n-1) // (m-1)
	for j in range(m):
		i = j * l
		if 0 <= i < n:
			k += 1
	print(k)
else:
	print(2)