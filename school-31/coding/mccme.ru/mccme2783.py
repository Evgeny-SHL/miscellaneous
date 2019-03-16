INF = float('inf')

n, m = [int(i) for i in input().split()]

t = [0] * n
for i in range(n):
	t[i] = [0] * n

for i in range(m):
	a, b, c = [int(i) for i in input().split()]
	t[a-1][b-1] = c

start = 0
finish = n-1
totalflow = 0

if start == finish:
	totalflow = INF
else:
	while True:
		flow = [0] * n
		visited = [False] * n
		p = [None] * n
		flow[start] = INF
		maxloc = None
		while True:
			maxloc = None
			maxflow = 0
			for i in range(n):
				if flow[i] > maxflow and not visited[i]:
					maxloc = i
					maxflow = flow[i]
			if maxloc is None:
				break
			if maxloc == finish:
				break
			visited[maxloc] = True
			for i in range(n):
				if t[maxloc][i] > 0 and flow[i] < min(maxflow, t[maxloc][i]):
					flow[i] = min(maxflow, t[maxloc][i])
					p[i] = maxloc
		if maxloc is None:
			break
		totalflow += flow[finish]
		j = p[finish]
		while j is not None and p[j] is not None:
			t[j][p[j]] += flow[finish]
			t[p[j]][j] -= flow[finish]
			j = p[j]

print(totalflow)