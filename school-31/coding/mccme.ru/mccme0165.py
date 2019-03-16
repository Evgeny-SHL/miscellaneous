n, m = [int(i) for i in input().split()]

t = []
for i in range(n):
    t.append([0] * n)

for i in range(m):
    a, b = [int(i) for i in input().split()]
    t[a-1][b-1] = 1
    t[b-1][a-1] = 1
    
RED = False
BLUE = True
def dfs(v, used, color, p):
    global f
    used[v] = True
    color[v] = not color[p];
    for u in range(len(t[v])):
        if (t[u][v] == 1) and (color[u] == color[v]):
            f = False
        if (t[u][v] == 1) and not used[u]:
            dfs(u, used, color, v)

f = True
used = [False] * n
color = [None] * n
for v in range(n):
    if not used[v]:
        color[v] = RED
        dfs(v, used, color, v)
if f:
    print('YES')
    for v in range(n):
        if color[v]:
            print(v+1, end = ' ')
else:
    print('NO')