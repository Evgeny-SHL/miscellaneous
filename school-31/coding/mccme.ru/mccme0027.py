a, b = [int(i) for i  in input().split()]

def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

g = gcd(abs(a), b)
a, b = a // g, b // g

print(a, b)