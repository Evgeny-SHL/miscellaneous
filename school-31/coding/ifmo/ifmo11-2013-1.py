k = 0
for a in range(1, 16):
	for b in range(0, 16):
		for c in range(0, 16):
			if not (a == 2 or b == 2 or c == 2):
				continue
			num = 256 * a + 16 * b + c
			sum = a + b + c
			if num > 2047:
				continue
			x = num
			x *= 2
			z = x % 16
			x //= 16
			y = x % 16
			x //= 16
			if x + y + z == a + b + c:
				k += 1
				print(k, num)