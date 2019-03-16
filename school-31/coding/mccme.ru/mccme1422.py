def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

a, b = [int(i) for i in input().split()]
print(lcm(a, b))