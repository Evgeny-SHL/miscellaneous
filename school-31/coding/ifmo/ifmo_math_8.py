m = set()

for x1 in [1, 3, 5]:
	for y1 in [1, 3, 5]:
		for z1 in [1, 3, 5]:
			for x2 in [1, 3, 5]:
				for y2 in [1, 3, 5]:
					for z2 in [1, 3, 5]:
						print(x1 * x2 + y1 * y2 + z1* z2)
						m.add(x1 * x2 + y1 * y2 + z1 * z2)
print(len(m))