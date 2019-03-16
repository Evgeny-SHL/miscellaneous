s = 0
k = True
while s <= 100:
	s += int(input())
	k = not k
if k:
	print('ENDER')
else:
	print('VALENTINE')