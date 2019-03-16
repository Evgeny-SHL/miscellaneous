def hanoi(n, start, extra, finish):
	if n == 1:
		print(1, start, finish)
		return
	hanoi(n-1, start, finish, extra)
	print(n, start, finish)
	hanoi(n-1, extra, start, finish)

n = int(input())
hanoi(n, 1, 2, 3);