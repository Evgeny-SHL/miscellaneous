n = int(input())
MAX = n

dels = [0] * (10 ** 5)
d = 2
while d < int(MAX ** 0.5) + 1:
	if n % d == 0:
		dels[d] += 1
		n //= d
	else:
		d += 1
		if d > 3:
			d += 1
	if n == 1:
		break

s = ''
for d in range(len(dels)):
	if dels[d] > 1:
		s += str(d) + '^' + str(dels[d]) + '*'
	elif dels[d] > 0:
		s += str(d) + '*'
if n > 1:
	s += str(n) + '*'
print(s[:len(s)-1])