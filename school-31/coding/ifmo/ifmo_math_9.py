for d in range(0, 99):
	k = 0
	for p in range(1, 99):
		if d % p == 0:
			k += 1
	if (d + k) == 98:
		print(d)