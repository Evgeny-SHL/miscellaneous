def build(a, tree, v, tl, tr):
	if tl == tr:
		tree[v] = a[tl]
	else:
		tm = (tl + tr) // 2
		build(a, tree, 2 * v + 1, tl, tm)
		build(a, tree, 2 * v + 2, tm + 1, tr)
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2]

def sum_t(tree, v, tl, tr, l, r):
	if l > r:
		return 0
	if l == tl and r == tr:
		return tree[v]
	tm = (tl + tr) // 2
	return sum_t(tree, 2 * v + 1, tl, tm, l, min(r, tm)) + sum_t(tree, 2 * v + 2, tm + 1, tr, max(l, tm + 1), r)

def update_t(tree, v, tl, tr, pos, new):
	if tl == tr:
		t[v] = new
	else:
		tm = (tl + tr) // 2
		if pos <= tm:
			update(tree, 2 * v + 1, tl, tm, pos, new)
		else:
			update(tree, 2 * v + 2, tm + 1, tr, pos, new)
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2]

a = [int(i) for i in input().split()]
n = len(a)
tree = [None] * (4 * n)
build(a, tree, 0, 0, n-1)

k = int(input())
print(tree)
for i in range(k):
	l, r = [int(i) for i in input().split()]
	print(sum_t(tree, 0, 0, n - 1, l, r))

for i in range(n):
	update(tree, 0, 0, n-1, i, n - i + 1)

k = int(input())
print(tree)
for i in range(k):
	l, r = [int(i) for i in input().split()]
	print(sum_t(tree, 0, 0, n - 1, l, r))