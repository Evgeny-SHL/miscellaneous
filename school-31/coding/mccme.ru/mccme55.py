class Stack:
	def __init__(self):
		self.data = [None] * 125
		self.len = 0
	def pop(self):
		if self.len == 0:
			print('error')
			return
		self.len -= 1
		print(self.data[self.len])
	def push(self, n):
		self.data[self.len] = n
		self.len += 1
		print('ok')
	def back(self):
		if self.len == 0:
			print('error')
			return
		print(self.data[self.len-1])
	def clear(self):
		self.data = [None] * 125
		self.len = 0
		print('ok')
	def size(self):
		print(self.len)
	def exit(self):
		print('bye')

a = Stack()

while True:
	s = input()
	if s == 'exit':
		a.exit()
		break
	if s == 'clear':
		a.clear()
	if s == 'back':
		a.back()
	if s == 'pop':
		a.pop()
	if s == 'size':
		a.size()
	if s[:4] == 'push':
		n = s[5:]
		a.push(n)
