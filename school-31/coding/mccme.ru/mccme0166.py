n, m = [int(i) for i in input().split()]

head = [None] * n
to = [None] * m
next = [None] * m

for v in range(m):
    a, b = [int(i) for i in input().split()]
    next[v] = head[a-1]
    to[v] = b-1
    head[a-1] = v
    
WHITE = 0
GRAY = 1
BLACK = 2
used = [False] * n
color = [WHITE] * n
time = [None] * n
cycle = False
timer = 0
def dfs(v):
    global used
    global cycle
    global color
    global time
    global timer
    used[v] = True
    color[v] = GRAY
    u = head[v]
    while u is not None:
        if color[to[u]] == GRAY:
            cycle = True
            return
        if cycle:
            return
        if color[to[u]] == WHITE:
            dfs(to[u])
        u = next[u]
    color[v] = BLACK
    time[timer] = str(v+1)
    timer += 1

for v in range(n):
    if not used[v]:
        dfs(v)
        
if not cycle:
    print('Yes')
    print(' '.join(time[::-1]))
else:
    print('No')