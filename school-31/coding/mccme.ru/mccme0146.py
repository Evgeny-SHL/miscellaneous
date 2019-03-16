a, b, c, d = [int(i) for i in input().split()]

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

m = a * d + b * c
n = b * d
m, n = m // gcd(m, n), n // gcd(m, n)

print(m, n)