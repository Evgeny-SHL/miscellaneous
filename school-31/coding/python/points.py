import math

k1 = 0
k2 = 0
k3 = 0
k = 0
s1 = 0
s2 = 0

n = int(input())

for p in range(0, n + 1):
	for pm in range(0, n + 1):
		for mp in range(0, n + 1):
			for m in range(0, n + 1):
				if p + pm + mp + m == n:
					b1 = p + pm / 2 + mp / 4
					b2 = p + (pm + 1) // 2 + mp // 2
					b1 = math.floor(10 * b1 / n) + 1
					if b1 >= 11:
						b1 = 10
					b2  = math.floor(10 * b2 / n) + 1
					if b2 >= 11:
						b2 = 10
					if b1 > b2:
						k1 += 1
					if b1 == b2:
						k2 += 1
					if b1 < b2:
						k3 += 1
					k += 1
					s1 += b1
					s2 += b2
				#	print('++', p, '+-', pm, '-+', mp, '--', m, b1, b2)

print(k1, k2, k3, k)
print(s1 / k, s2 / k)