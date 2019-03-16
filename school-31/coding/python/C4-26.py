s = input()
k = [0] * 10

t = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

for i in range(len(s)):
	if ord(s[i]) > 126 or ord(s[i]) < 32:
		print(s[i])
	if s[i] in t:
		k[ord(s[i]) - 48] += 1

ans = ''
m = 0

for i in range(10):
	for j in range(k[i] // 2):
		print(i, sep = '', end = '')
	if m == 0 and k[i] % 2 == 1:
		m = i

if m != 0:
	print(m, sep = '', end = '')

for i in range(9, -1, -1):
	for j in range(k[i] // 2):
		print(i, sep = '', end = '')

print(ans)