def run():
	a, b = [int(i) for i in input().split()]

	k = 0
	while a > 0 and b > 0:
		if a > b:
			k += a // b
			a %= b
		else :
			k += b // a
			b %= a
	print(k)

run()