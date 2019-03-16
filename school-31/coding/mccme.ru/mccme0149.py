n = int(input())

def lagrange(n):
    for a in range(int(n ** 0.5) + 1):
        for b in range(int((n - a*a) ** 0.5) + 1):
            for c in range(int((n - a*a - b*b) ** 0.5) + 1):
                d = int((n - a*a - b*b - c*c) ** 0.5)
                if a*a+b*b+c*c+d*d == n:
                    if d != 0:
                        print(d, end = ' ')
                    if c != 0:
                        print(c, end = ' ')
                    if b != 0:
                        print(b, end = ' ')
                    if a != 0:
                        print(a, end = ' ')
                    return
                
lagrange(n)