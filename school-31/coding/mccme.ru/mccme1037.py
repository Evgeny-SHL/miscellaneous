def max_div(a):
	for i in range(2, int(a ** 0.5) + 1):
		if a % i == 0:
			return a // i
	return 1

n = int(input())
d = max_div(n)
n //= d

print(d, (n-1) * d)