def res():
    n, m = [int(i) for i in input().split()]
    
    first = [None] * n
    next = [None] * 2 * m
    edge = [None] * 2 * m
    
    for e in range(m):
        a, b = [int(i)-1 for i in input().split()]
        edge[e] = b
        if first[a] is not None:
            next[e] = first[a]
        first[a] = e
        edge[e+m] = a
        if first[b] is not None:
            next[e+m] = first[b]
        first[b] = e+m 
        
    used = [False] * n
    components = []
    def dfs(v):
        used
        components
        used[v] = True
        u = first[v]
        while u is not None:
            if not used[edge[u]]:
                components[len(components)-1].append(str(edge[u]+1))
                dfs(edge[u])
            u = next[u]
            
    for v in range(n):
        if not used[v]:
            components.append([str(v+1)])
            dfs(v)
            
    print(len(components))
    for i in range(len(components)):
        print(len(components[i]))
        print(' '.join(components[i]))
        
res()