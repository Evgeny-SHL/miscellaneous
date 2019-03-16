def diag1(a, k, n, i0, j0):
	p, q, t = i0, j0, 0
	while a[p][q] and t < k:
		p += 1
		q += 1
		t += 1
	p, q = i0-1, j0-1
	while a[p][q] and t < k:
		p -= 1
		q -= 1
		t += 1
	if t >= k:
		return True
	return False

def diag2(a, k, n, i0, j0):
	p, q, t = i0, j0, 0
	while a[p][q] and t < k:
		p += 1
		q -= 1
		t += 1
	p, q = i0-1, j0+1
	while a[p][q] and t < k:
		p -= 1
		q += 1
		t += 1
	if t >= k:
		return True
	return False

def row(a, k, n, i0, j0):
	p, q, t = i0, j0, 0
	while a[p][q] and t < k:
		q += 1
		t += 1
	p, q = i0, j0-1
	while a[p][q] and t < k:
		q -= 1
		t += 1
	if t >= k:
		return True
	return False

def column(a, k, n, i0, j0):
	p, q, t = i0, j0, 0
	while a[p][q] and t < k:
		p += 1
		t += 1
	p, q = i0-1, j0
	while a[p][q] and t < k:
		p -= 1
		t += 1
	if t >= k:
		return True
	return False

def win(a, k, n, i, j):
	return diag1(a, k, n, i, j) or diag2(a, k, n, i, j) or row(a, k, n, i, j) or column(a, k, n, i, j)

n, k, m = [int(i) for i in input().split()]

a = [False] * (n+1)
for i in range(n+1):
	a[i] = [False] * (n+1)

if m >= k:
	for p in range(1, m+1):
		i, j = [int(q)-1 for q in input().split()]
		a[i][j] = True
		if a[i+1][j] or a[i][j+1] or a[i-1][j] or a[i][j-1] or a[i+1][j+1] or a[i+1][j-1] or a[i-1][j+1] or a[i-1][j-1]:
			if win(a, k, n, i, j):
				print(p)
				break
	else:
		print(0)
else:
	print(0)