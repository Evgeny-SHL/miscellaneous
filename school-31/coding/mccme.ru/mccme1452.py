x1, y1, x2, y2 = [int(i) for i in input().split()]
dx = abs(x1 - x2)
dy = abs(y1 - y2)

def gcd(a, b):
    while b != 0:
          a, b = b, a % b
    return a

print(gcd(dx, dy) + 1)