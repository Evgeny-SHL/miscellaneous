# 1. Проверка на простоту.
def is_prime(a):
    for i in range(2, int(a ** 0.5)+1):
        if a % i == 0:
            return False
    return True

# 2. Наименьший делитель числа.
def least_div(a, b = 2):
    for i in range(b, int(a ** 0.5)+1):
        if a % i == 0:
            return i
    return a

# 3. Наибольший делитель числа.
def largest_div(a):
    d = least_div(a)
    if d != a:
        return a // d
    return a

# 4. Разложение на простые множители (факторизация).
def factor(a):
    f = []
    k = 0
    d = 2
    while a > 1:
        d = least_div(a, d)
        f += [d]
        a //= d
    return f

# 5. Алгоритм Евклида.
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# 6. Наименьшее общее кратное.
def lcm(a, b):
    return a // gcd(a, b) * b

# 7. Решето Эратосфена.
def erat(n):
    p = [True] * (n+1)
    for i in range(2, n+1): 
        if p[i]:
            for j in range(i*i, n+1, i):
                p[j] = False
    return [i for i in range(n+1) if p[i] and (i > 1)]

# 8. Линейный поиск.
def is_found(a, n):
    for x in a: 
        if x == n:
            return True
    return False

# 9. Поиск максимального элемента.
def maximum(a):
    best1 = a[0]
    for x in a:
        best1 = max(best1, x)
    return best1

# 10. Поиск минимального элемента. 
def minimum(a):
    best1 = a[0]
    for x in a:
        best1 = min(best1, x)
    return best1

# 11. Два максимальных элемента.
def two_max(a):
    best1 = a[0]
    best2 = a[0]
    for x in a:
        best1, best2 = max(best1, x), max(best2, min(best1, x))
    return [best1, best2]

# 12. Два минимальных элемента.
def two_min(a):
    best1 = a[0]
    best2 = a[0]
    for x in a:
        best1, best2 = min(best1, x), min(best2, max(best1, x))
    return [best1, best2]

# 13. Сортировка пузырьком.
def bubble_sort(source, f = True):
    a = source[:]
    for step in range(1, len(a) - 1):
        for i in range(len(a) - step - 1):
            if f:
                a[i], a[i+1] = min(a[i], a[i+1]), max(a[i], a[i+1])
            else:
                a[i], a[i+1] = max(a[i], a[i+1]), min(a[i], a[i+1])

# 14. Сортировка выбором.
def selection_sort(source, f = True):
    a = source[:]
    for i in range(len(a)-1):
        tail = a[i:]
        j = i
        if f:
            j += tail.index(min(tail))
        else:
            j += tail.index(max(tail))
        a[i], a[j] = a[j], a[i]
    return a

# 15. Сортировка подсчетом.
def counting_sort(source, f = True):
    m = min(source)
    a = [0] * (max(source) - m + 1)
    for x in source:
        a[x - m] += 1
    b = []
    k = 0
    if f:
        r = range(len(a))
    else:
        r = range(len(a)-1, -1, -1)
    for i in r:
        for j in range(a[i]):
            b += [i + m]
            k += 1
    return b

# 16. Рекурсивный перебор последовательностей из чисел от 0 до m-1 длиной n. Размещения с повторениями.
def recurs_enum(n, m = 2):
    ans = []
    place = [None] * n
    def rec(n, m, ans):
        if n > 0:
            for i in range(m-1, -1, -1):
                place[n-1] = i
                rec(n-1, m, ans)
        else:
            ans += [place[:]]
    rec(n, m, ans)
    return ans[::-1]

# 17. Рекурсивный перебор подмножеств.
def recurs_subsets(n):
    ans = []
    place = [None] * n
    def rec(n, ans):
        if n > 0:
            for i in range(2):
                place[n-1] = i
                rec(n-1, ans)
        else:
            ans += [[i for i in range(len(place)) if place[i] == 1][:]]
    rec(n, ans)
    return ans

# 18. Рекурсивный перебор сочетаний из n элементов по k.
def recurs_combins(n, k):
    ans = []
    place = [None] * n
    def rec(n, i, k, ones, zeroes, ans):
        if i > 0:
            if ones < k:
                place[i-1] = 1
                rec(n, i-1, k, ones+1, zeroes, ans)
            if zeroes < n - k:
                place[i-1] = 0
                rec(n, i-1, k, ones, zeroes+1, ans)
        else:
            ans += [place[:]]
    rec(n, n, k, 0, 0, ans)
    return ans

# 19. Сортировка слиянием.
def merge_sort(a, f = True):
    start = 0
    finish = len(a)
    def sorting(a, start, finish, f):
        mid = (start + finish) // 2
        if mid - start > 1:
            b = sorting(a, start, mid, f)
        else:
            b = a[start:mid]
        if finish - mid > 1:
            c = sorting(a, mid, finish, f)
        else:
            c = a[mid:finish]
        i = 0
        j = 0
        b += [float('inf')]
        c += [float('inf')]
        if not f:
            b[len(b)-1] *= -1
            c[len(c)-1] *= -1
        while (i < len(b) - 1) or (j < len(c) - 1):
            if f:
                if b[i] <= c[j]:
                    a[start+i+j] = b[i]
                    i += 1
                else:
                    a[start+i+j] = c[j]
                    j += 1
            else:
                if b[i] >= c[j]:
                    a[start+i+j] = b[i]
                    i += 1
                else:
                    a[start+i+j] = c[j]
                    j += 1                
        return a[start:finish]
    return sorting(a, start, finish, f)

# 20. Правый бинарный поиск
def bisect_right(a, x):
    left, right = 0, len(a)
    while right - left > 1:
        mid = (left + right) // 2
        if x >= a[mid]:
            left = mid
        else:
            right = mid
    if x == a[left]:
        return left
    
# 21. Левый бинарный поиск
def bisect_left(a, x):
    left, right = -1, len(a) - 1
    while right - left > 1:
        mid = (left + right) // 2
        if x > a[mid]:
            left = mid
        else:
            right = mid
    if x == a[right]:
        return right

# 22. Задача "Ксерокопии".
# Секретарша Ирочка сегодня опоздала на работу и ей срочно нужно успеть к обеду сделать n копий одного документа.
# В ее распоряжении имеются два ксерокса, один из которых копирует лист за х секунд, а другой – за y секунд.
# (Разрешается использовать как один ксерокс, так и оба одновременно. Можно копировать не только с оригинала, но и с копии.)
# Помогите ей выяснить, какое минимальное время для этого потребуется.
def xerox(n, x, y):
    def is_printed(n, x, y, t):
        return (t//x + t//y) >= (n-1)
    left = 0
    t1 = min(x, y)
    right = t1 * n + 1
    while right - left > 1:
        mid = (left + right) // 2
        if is_printed(n, x, y, mid):
            right = mid
        else:
            left = mid
    return t1 + right

# 23. Поиск в глубину.
def dfs(graph):
    WHITE = 0
    GRAY = 1
    BLACK = 2
    color = [WHITE] * len(graph)
    def search(v, graph, color):
        color[v] = GRAY
        for u in range(len(graph[v])):
            if graph[v][u] and (color[u] == WHITE):
                search(u, graph, color)
        color[v] = BLACK
    for v in range(len(graph)):
        search(v, graph, color)

# 24. Поиск хотя бы одного цикла
# в ориентированном и неориентированном графе.
def search_cylce(graph, oriented = True):
    WHITE = 0
    GRAY = 1
    BLACK = 2
    color = [WHITE] * len(graph)
    cycle = []
    def search(v, graph, color, cycle, f, oriented, p):
        color[v] = GRAY
        for u in range(len(graph[v])):
            if graph[v][u] and (color[u] == WHITE):
                f = search(u, graph, color, cycle, f, oriented, v)
            if (graph[v][u] and (color[u] == GRAY) and ((p != u) or oriented) or f) and ((p != v) or oriented):
                cycle += [[v, u][:]]
                color[u] = BLACK
                return True
        color[v] = BLACK
        return False
    for v in range(len(graph)):
        search(v, graph, color, cycle, False, oriented, v)
    return cycle[::-1]

# 25. Проверка графа на двудольность.
def is_bipartite(graph):
    WHITE = 0
    GRAY = 1
    BLACK = 2
    RED = 1
    BLUE = 2
    color = [WHITE] * len(graph)
    color2 = [RED] * len(graph)
    def search(v, graph, color, color2, col):
        color[v] = GRAY
        for u in range(len(graph[v])):
            if graph[v][u] and (color[u] == WHITE):
                if color2:
                    search(u, graph, color, color2, color2[u])
        color[v] = BLACK
        return True
    f = False
    for v in range(len(graph)):
        f = f or search(v, graph, color, color2, RED)
    return f

# 26. Топологическая сортировка.


# 27. Реализация структуры данных очередь.

# 28. Реализация очереди на базе закольцованного массива.

# 29. Волновой алгоритм.

# 30. Поиск в ширину.

# 31. Восстановление кратчайшего пути.

# 32. Динамическое программирование. Числа Фибоначчи.

# 33. Задача о кузнечике. Количество путей. Самый выгодный путь. Путь с препятствиями.

# 34. Задача о кузнечике. Восстановление пути. Обратный ход.

# 35. Задача о кузнечике. Восстановление пути. Запоминание лучшего.

# 36. Задача о черепашке.

# 37. Наибольшая общая подпоследовательность. Длина подпоследовательности. Восстановление подпоследовательности.

# 38. Наибольшая возрастающая подпоследовательность. Длина подпоследовательности. Восстановление подпоследовательности.

print(merge_sort([9, 8, 7, 6, 5, 4, 3, 2, 1, 0]))
