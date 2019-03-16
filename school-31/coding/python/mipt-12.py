s = 110000
s1 = s // 2
s2 = s // 5
k = 0
for a in range(0, s2 + 1):
	for b in range(0, s1 + 1):
		if 5 * a + 2 * b <= s:
			k += 1
print(k)