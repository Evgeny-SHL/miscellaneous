a, b, c = [int(i) for i in input().split()]

def gcd(a, b):
	while b!= 0:
		a, b = b, a % b
	return a

n = gcd(a, b)

if c % n != 0:
	print('Impossible')
else:
	x = 1
	while True:
		y = (c - a*x) // b
		if a*x+b*y == c:
			print(n, x, y)
			break
		x += 1