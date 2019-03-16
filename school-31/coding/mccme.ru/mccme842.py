n = int(input())

a = 1
b = 1
c = 1
for i in range(1, n):
	a, b, c = b, c, (b % 10 + c % 10) % 10

print(c)