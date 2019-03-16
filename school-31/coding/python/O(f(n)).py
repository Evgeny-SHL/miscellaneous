from math import log
l = 1.0
r = 10.0 ** 8.0
for t in range(1, 100):
	n = (l + r) / 2
	if (n * log(n, 2) < 10 ** 8):
		l = n
	else:
		r = n
print(l)