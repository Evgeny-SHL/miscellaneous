for n in range(2, 10):
	k = 0
	for m in range(n * n, n * n * n):
		if m % n != m % (n * n):
			k += 1
	if k >= 200:
		print(n)
		break