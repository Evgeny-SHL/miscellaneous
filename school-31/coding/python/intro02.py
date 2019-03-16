n = int(input())
for i in range(1, n + 1):
	if i % 21 == 0:
		print(i, end = ' ')
	elif i % 3 == 0:
		print(i, end = ' ')
		print(i, end = ' ')
	elif i % 7 != 0:
		print(i, end = ' ')