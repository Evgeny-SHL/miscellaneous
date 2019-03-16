class Stack:

	def __init__(self):
		self.data = [None] * 110
		self.len = 0

	def push(self, n):
		self.data[self.len] = n
		self.len += 1
		print('ok')

	def pop(self):
		print(self.data[self.len-1])
		self.len -= 1

	def back(self):
		print(self.data[self.len-1])

	def size(self):
		print(self.len)

	def clear(self):
		self.data = [None] * 110
		self.len = 0
		print('ok')

	def exit(self):
		print('bye')

a = Stack()

while True:
	s = input()
	if s == 'exit':
		a.exit()
		break
	if s == 'back':
		a.back()
	if s == 'clear':
		a.clear()
	if s == 'size':
		a.size()
	if s == 'pop':
		a.pop()
	if s[:4] == 'push':
		n = int(s[5:])
		a.push(n)