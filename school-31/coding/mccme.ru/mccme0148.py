n = int(input())

def least_div(a, b = 2):
    for i in range(b, int(a ** 0.5) + 1):
        if a % i == 0:
            return i
    return a

def fact(a):
    d = 2
    while a > 1:
        d = least_div(a, d)
        print(d, end = ' ')
        a //= d
        
fact(n)