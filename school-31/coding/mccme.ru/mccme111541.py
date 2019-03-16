n = int(input())

t = []
for i in range(n):
    t.append([int(i) for i in input().split()])

WHITE = 0
GRAY = 1
BLACK = 2
used = [False] * n
color = [WHITE] * n
cycle = False
def dfs(v, p):
    global used
    global cycle
    global color
    used[v] = True
    color[v] = GRAY
    for u in range(n):
        if t[v][u] == 1 and color[u] == GRAY and u != p:
            cycle = True
            return
        if cycle:
            return
        if t[v][u] == 1 and color[u] == WHITE:
            dfs(u, v)
    color[v] = BLACK

k = 0
for v in range(n):
    if not used[v]:
        k += 1
        dfs(v, v)

if not cycle and k == 1:
    print('YES')
else:
    print('NO')