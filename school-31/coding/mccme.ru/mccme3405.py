n = int(input())

def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

for x in range(n // 2, 0, -1):
	y = n - x
	if gcd(x, y) == 1:
		print(x, y)
		break