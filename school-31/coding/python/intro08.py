from queue import Queue

old = [None] * (k + 10)
new = [None] * (k + 10)
used = [False] * (10 ** l + 10)

q = Queue()

l = int(input())
s = int(input())
t = int(input())
k = int(input())

for i in range(0, k):
	old[i], new[i] = [int(j) for j in input().split()]

class state:
	def __init__(self, a, b):
		self.num = a
		self.dist = b

def bfs(s, t, k):
	global old
	global new
	global used
	global q

	q.put(state(s, 0))
	while not q.empty():
		ksi = q.get()
		if ksi.num == t:
			return ksi.dist
		used[ksi.num] = True
		for i in range(0, k):
			x = str(ksi.num)
			y = str(old[i])
			z = str(new[i])
			j = x.find(y)
			while j != -1:
				x1 = x[:j] + x[j:].replace(y, z, 1)
				x1 = int(x1)
				if x1 == t:
					return ksi.dist + 1
				if not used[x1]:
					q.put(state(x1, ksi.dist + 1))
				j = x.find(y, j + 1)
	return -1

print(bfs(s, t, k))