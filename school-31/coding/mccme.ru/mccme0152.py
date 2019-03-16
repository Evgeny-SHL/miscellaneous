n = int(input())

def prime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

for x in range(2, n-1):
    y = n - x
    if prime(x) and prime(y):
        print(x, y)
        break