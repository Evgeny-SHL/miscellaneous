/*

B. Порядок вершин
Ограничение времени	5 секунд
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Вершины ориентированного графа занумерованы натуральными числами от
1
 до
n
. Напишите программу, выводящую все возможные упорядочения вершин графа
i
1
,
…
,
i
n
, для которых
i
s
<
i
t
 всякий раз, когда существует стрелка
i
s
→
i
t
, или определяющую, что таких нет.
Формат ввода
В первой строке указано натуральное число
n
 (
1
≤
n
≤
1
2
) — количество вершин графа. Во второй указано натуральное число
m
 — количество стрелок. Следующие
m
 строчек — это пары натуральных чисел
s
i
,
t
i
 (
1
≤
s
i
,
t
i
≤
n
) — номера начала и конца стрелки, разделённые пробелом.
Формат вывода
Ваша программа должна вывести no, если искомых упорядочений не существует. В противном случае в первой строке необходимо вывести количество искомых упорядочений
k
, после чего перечислить в лексикографическом порядке по возрастанию все подходящие упорядочения вершин. Каждое упорядочение указываются в отдельной строке; вершины должны быть отделены пробелами.
Гарантируется, если искомые упорядочения существуют, то их не более
2
0
0
0
0
0
.



*/

#include <bits/stdc++.h>

class Graph {
 public:
  explicit Graph(size_t n) : l(n + 1, std::vector<size_t>()) {
  }

  void AddEdge(size_t from, size_t to) {
    l[from].push_back(to);
  }

  bool HasCycle() {
    size_t n = l.size() - 1;
    std::vector<size_t> v(n + 1);

    for (size_t c = 1; c <= n; ++c) {
      if (!v[c] && HasCycleFrom(c, v)) {
        return true;
      }
    }

    return false;
  }

 private:
  bool HasCycleFrom(size_t c, std::vector<size_t>& v) {
    v[c] = 1;

    for (auto&& n : l[c]) {
      if (v[n] == 1) {
        return true;
      }

      if (v[n] == 0 && HasCycleFrom(n, v)) {
        return true;
      }
    }

    v[c] = 2;

    return false;
  }

 private:
  std::vector<std::vector<size_t>> l;
};

bool IsOk(const std::vector<size_t> &v,
          size_t i,
          const std::set<std::pair<size_t, size_t>> &r) {
  for (auto &&j : v) {
    if (i == j || r.find({i, j}) != r.end()) {
      return false;
    }
  }

  return true;
}

void Permute(size_t l,
             size_t n,
             std::vector<size_t> &v,
             const std::set<std::pair<size_t, size_t>> &r,
             std::vector<std::vector<size_t>> &a) {
  if (l == n) {
    a.push_back(v);
    return;
  }

  for (size_t i = 1; i <= n; ++i) {
    if (IsOk(v, i, r)) {
      v.push_back(i);
      Permute(l + 1, n, v, r, a);
      v.pop_back();
    }
  }
}

int main() {
  size_t n = 0;
  std::cin >> n;

  Graph g(n);

  size_t m = 0;
  std::cin >> m;

  std::set<std::pair<size_t, size_t>> r;
  for (size_t i = 0; i < m; ++i) {
    size_t x = 0;
    size_t y = 0;
    std::cin >> x >> y;

    r.emplace(x, y);
    g.AddEdge(x, y);
  }

  if (g.HasCycle()) {
    std::cout << "no" << std::endl;
    return 0;
  }

  std::vector<std::vector<size_t>> a;
  std::vector<size_t> v;
  Permute(0, n, v, r, a);

  if (a.empty()) {
    std::cout << "no" << std::endl;
    return 0;
  }

  std::cout << a.size() << std::endl;
  for (auto &&y : a) {
    for (auto &&x : y) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
}
