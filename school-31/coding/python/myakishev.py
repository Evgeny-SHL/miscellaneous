EPS = 10 ** -6;
ro = 1000
ro1 = 1000
ro2 = 1000
a = 5 * 10 ** -6

t = 0
while abs(ro1/ro2 - 1) <= EPS:
	t += 1
	ro1 = ro / (1 + a * t)
	ro2 = ro * (1 - a * t)

print(t)