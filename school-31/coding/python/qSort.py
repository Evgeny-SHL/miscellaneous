def qSort(a):
    def sorting(a, l, r):
        i = l
        j = r
        x = a[(l + r) // 2]
        while True:
            while a[i] < x:
                i += 1
            while a[j] > x:
                j -= 1
            if i <= j:
                a[i], a[j] = a[j], a[i]
                i += 1
                j -= 1
            if i > j:
                break
        if j - l > 0:
            sorting(a, l, j)
        if r - i > 0:
            sorting(a, i, r)
    if len(a) > 1:
        sorting(a, 0, len(a)-1)
    return a

a = [10, 9, 8, 7, 7, 5, 4, 3, 2, 1, 7, 5, 7, 2, 8, 8, 7]

print(a)
qSort(a)
print(a)