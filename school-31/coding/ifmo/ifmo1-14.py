a = [7, 3, 4, 2, 6, 5, 1, 3, 2, 4, 5, 6, 1, 4]

i = 0
c = 0
d = 13
n = 9
while True:
	if a[i] < n:
		c = c + a[i] % 2
		i += 1
	else:
		print('ERROR')
		break
	if i > d:
		break

r = None
if n % 2 == 0:
	r = a[d] % 2
else:
	r = c % 2
print(r)