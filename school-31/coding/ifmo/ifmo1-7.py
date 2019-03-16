def A(x):
	return x * (x + 6) < 12

def B(x):
	return x > 7

def C(x):
	return 17 < x + 3

count = 0
for x in range(1, 16):
	if not A(x) and not B(x) or C(x):
		count += 1
		print(x)

print(count)