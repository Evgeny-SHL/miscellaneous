from math import log
l = 1.0
r = 10.0 ** 8.0
print(l, r)
for t in range(1, 100):
	m = (l + r) / 2
	if (n * log(n, 2) < 10 ** 8):
		l = m
	else:
		r = m
print(l)