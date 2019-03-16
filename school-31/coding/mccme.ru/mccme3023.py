def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

n = int(input())

g = 0
for i in input().split():
	g = gcd(g, int(i))
	if g == 1:
		break

print(g)