def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

n = int(input())
fractions = []

for i in range(1, n):
	for j in range(i+1, n+1):
		if gcd(i, j) == 1:
			fractions.append({ 'value': i/j, 'a': i, 'b': j})

fractions.sort(key = lambda fractions: fractions['value'])

for i in range(len(fractions)):
	print(fractions[i]['a'], fractions[i]['b'], sep = '/')