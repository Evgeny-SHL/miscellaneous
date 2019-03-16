for a in range(2, 17):
	for b in range(2, 17):
		for c in range(2, 17):
			if a < c and b < c and c < a + b < 2*c:
				ab = int(str(int(str(a) + str(b), c)), 10)
				c13 = int(str(int('13' + str(c), a + b)), 10)
				if ab + ab == c13:
					print(a, b, c)
					print(ab, c13)

print(2 ** 10000)