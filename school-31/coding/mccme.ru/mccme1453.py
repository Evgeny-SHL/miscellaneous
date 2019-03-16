n = int(input())

m = 1
MAX = 10 ** 500
while m < MAX:
      if m % n == 0:
         print(m)
         break
      m = (10 * m) + 1
else:
     print('NO')