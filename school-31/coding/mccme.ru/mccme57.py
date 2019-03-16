class Queue:
	def __init__(self):
		self.data = [None] * 1000
		self.len = 0
		self.start = 0

	def push(self, x):
		self.data[self.len] = x
		self.len += 1
		print('ok')

	def pop(self):
		print(self.data[self.start])
		self.start += 1

	def front(self):
		print(self.data[self.start])

	def size(self):
		print(self.len - self.start)

	def clear(self):
		self.len = 0
		self.start = 0
		print('ok')

	def exit(self):
		print('bye')

q = Queue()

while True:
	s = input()
	if s[:4] == 'push':
		q.push(int(s[5:]))
	elif s == 'pop':
		q.pop()
	elif s == 'front':
		q.front()
	elif s == 'size':
		q.size()
	elif s == 'clear':
		q.clear()
	else:
		q.exit()
		break