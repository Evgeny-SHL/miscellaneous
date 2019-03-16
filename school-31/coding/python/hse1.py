s = 0
for i in range(200):
	if i % 7 != 0 and 9 <= i / 7 <= 27:
		s += i / 7
print(s)