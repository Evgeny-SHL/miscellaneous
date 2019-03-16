a, b = [int(i) for i in input().split()]

def gcd(a, b):
	if b != 0:
		return gcd(b, a % b)
	return a

print(gcd(a, b))