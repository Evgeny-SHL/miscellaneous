s = input()

n = len(s)
m = 0

for i in range(n):
	m = m + (i+1) * (ord('F') - ord(s[i]));

m *= 2 / (n * (n +1))

print(m)