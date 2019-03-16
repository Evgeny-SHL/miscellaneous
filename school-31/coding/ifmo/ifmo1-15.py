e = 420

n = 12
f = True # Диван
if f:
	e -= 4 * 6
else:
	e -= 6 * 6
while n > 0:
	if f:
		e -= 3 * n
	else:
		e -= n
	e -= 3 * 6
	n -= 1
	f = not f
e += 3 * 6
f = not f
if f:
	e -= 4 * 6
else:
	e -= 6 * 6
print(e)