N = 16
MAX = N * (N * (N + 1) + 1)

for i in range(N, -1, -1):
	for j in range(N - i, -1, -1):
		for k in range(N - i - j, -1, -1):
			l = N - i - j - k
			if l >= 0:
			#	print(i, j, k, l, 1000 * ((N * (N + 1) + 1) * i + (N + 1) * j + k) // (N * (N * (N + 1) + 1)))
				print(i, j, k, l, ((N * (N + 1) + 1) * i + (N + 1) * j + k) / MAX)