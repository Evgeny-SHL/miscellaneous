def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
n = int(input())
m = [int(i) for i in input().split()]
for i in range(n):
    m[0] = gcd(m[0], m[i])
print(m[0])