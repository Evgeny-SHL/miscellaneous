def run():
	n = int(input())

	def gcd(a, b):
		while b != 0:
			a, b = b, a % b
		return a

	k = 0
	x1, y1 = [int(i) for i in input().split()]
	x0, y0 = x1, y1
	for i in range(n-1):
		x2, y2 = x1, y1
		x1, y1 = [int(i) for i in input().split()]
		dx, dy = abs(x1 - x2), abs(y1 - y2)
		k += gcd(dx, dy)
	dx, dy = abs(x1 - x0), abs(y1 - y0)
	k += gcd(dx, dy)

	print(k)

run()