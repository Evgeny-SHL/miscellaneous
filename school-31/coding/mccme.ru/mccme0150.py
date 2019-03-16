n = int(input())

def cube(n):
    for a in range(int(n ** (1/3)) + 1):
        b = int((n - a*a*a) ** (1/3))
        if a*a*a + b*b*b == n:
            print(a, b)
            return
        else:
            b += 1
            if a*a*a + b*b*b == n:
                print(a, b)
                return            
    print('impossible')
    
cube(n)