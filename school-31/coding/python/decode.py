nums = "1000100 11010 200 441 303 225 40 130 105 98 85 26 7C 7C 6D 5D 5B 60 5F 30 1A 3F 48 41 16 3Q 3H 45 12 3C 3J W 20 2R 2P".split()
print(nums)
i = 2
for s in nums:
#	print(s, int(s, i))
	print(chr(int(s, i)), end = '')
	i += 1
	print(i)
print(num)