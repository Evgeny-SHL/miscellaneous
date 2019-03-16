n, v = [int(i) for i in input().split()]
m = []
for i in range(n):
    m.append([int(i) for i in input().split()])

used = [False] * n
def dfs(v, used, k = 1):
    used[v] = True
    for j in range(len(m[v])):
        if (m[v][j] == 1) and not used[j]:
            k = dfs(j, used, k + 1)
    return k

print(dfs(v-1, used))