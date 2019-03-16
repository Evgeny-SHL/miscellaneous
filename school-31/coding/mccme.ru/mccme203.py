n = int(input())

f = [0] * (n+4)

f[0] = 1
f[1] = 1
f[2] = 2
f[3] = 4
for i in range(4, n+1):
	f[i] = f[i-1] + f[i-2] + f[i-3]

print(f[n])