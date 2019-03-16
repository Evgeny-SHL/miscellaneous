inp = open("input.txt", "r")
outp = open("output.txt", "w")

n = int(inp.readline())
print(n)
for i in range(n):
	s = 'Case #' + str(i+1) + ': '
	outp.write("Case #")
	a, dig, b = [i for i in inp.readline().split()]

	print(a, dig, b)