n, m = [int(i) for i in input().split()]

first = [None] * n
edge = [None] * (2*m)
next = [None] * (2*m)

for e in range(0, 2*m, 2):
    a, b = [int(i)-1 for i in input().split()]
    edge[e] = b
    if first[a] is not None:
        next[e] = first[a]
    first[a] = e
    edge[e+1] = a
    if first[b] is not None:
        next[e+1] = first[b]
    first[b] = e+1
    
    
#print(first)
#print(next)
#print(edge)

RED = True
BLUE = False
di = True
used = [False] * n
color = [None] * n
def dfs(v, p):
    global di
    global used
    global color
    global first
    global next
    global edge
    used[v] = True
    color[v] = not color[p]
    u = first[v]
    while u is not None:
        if color[edge[u]] == color[v] and p != edge[u]:
            di = False
        if not di:
            return
        if not used[edge[u]]:
            dfs(edge[u], v)
        u = next[u]

for v in range(n):
    if not used[v]:
        dfs(v, v)
        
if di:
    print('YES')
else:
    print('NO')