n, a, b, c = [int(i) for i in input().split()]
MOD = 10 ** 9 + 7

s = 0

fact = [1] * (n+1)
for i in range(1, n+1):
	fact[i] = fact[i-1] * i

for i in range(a, n+1):
	for j in range(b, n+1-a):
		k = n - i - j
		if k >= c:
			m = (fact[n] // fact[i] // fact[j] // fact[k]) % MOD
		#	print(i, j, k)
			s = (s + m) % MOD

print(s)