for a in range(5, 100, 5):
	for b in range(a, 100-a, 5):
		for c in range(b, 100-a-b, 5):
			for d in range(c, 100-a-b-c, 5):
				e = 100 - (a + b + c + d)
		#		if e > d:
				print(100-a, 100-a-b, 100-a-b-c, 100-a-b-c-d, 100-a-b-c-d-e)