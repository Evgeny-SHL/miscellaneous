# def coffee(line, a, b, c):
# 	return line == a or line == b or line == c

# ans = 1000
# for a in range(1, 20):
# 	for b in range(a + 1, 20):
# 		for c in range(b + 1, 20):
# 			n = 1 # увеличение на каждую строчку
# 			t = 0 # прошло времени
# 			tc = 1 # строка перед последней чашкой
# 			for line in range(1, 21):
# 				t += 1 + n * (line - tc)
# 				if coffee(line, a, b, c):
# 					n += 1
# 					tc = line + 1
# 					t += 5
# 			ans = min(t, ans)
# 			print(t, a, b, c)
# print(ans)

def print_answer(n):
    for a in range(1, 101):
        for b in range(1, 101):
            c = (a ** n + b ** n) ** (1.0 / n)
            if int(c) == c and a != b and a != c and b!= c:
                print(a, b, int(c))
                return
    print(-1)


n = int(input())
print_answer(n)