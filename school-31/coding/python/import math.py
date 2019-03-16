import math

def Dima(n):
    num = math.factorial(n * n - n) / (math.factorial(n) * math.factorial(n * n - 2 * n))
    ans = math.factorial(n)
    sum = 0
    for k in range(0, n + 1):
        sum += ((-1) ** k) / math.factorial(k)
    ans *= sum
    return ans / num

def Evgeny(n):
    num = math.factorial(n * n - n) / (math.factorial(n) * math.factorial(n * n - 2 * n))
    ans = 1
    for k in range(1, n + 1):
        sum = 0
        for i in range(1, k):
            sum += 2 * n - (2 * k - 1)
        print(sum)
        ans *= n * n - n - sum
    ans /= math.factorial(n)
    return ans / num

print(Dima(8))
print(Evgeny(8))