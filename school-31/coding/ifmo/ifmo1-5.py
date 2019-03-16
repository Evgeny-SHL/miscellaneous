a = 24 * 1024
b = 8 * 1024
f = 2048 * 1360 * 24 // 8
mem = 192 * 1024 * 1204

m1 = 3 * f + a + b + b
m2 = f + a

x = 0
while x * m1 + 3 * x * m2 <= mem:
	if x % 3 == 0:
		print(x)
	x += 1