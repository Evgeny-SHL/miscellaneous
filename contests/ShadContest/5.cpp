/*

D. Минимальное остовное дерево, часть 1
Ограничение времени	3 секунды
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Условия обеих задач под названием «Минимальное остовное дерево» совпадают. Задачи отличаются только ограничениями на входные данные.


Вам дан неориентированный взвешенный граф с n вершинами и m рёбрами. Требуется выполнить q запросов вида «уменьшить вес ребра номер i на 1». После каждого запроса вам нужно вывести вес минимального остовного дерева в графе.

Остовное дерево графа — это подграф, содержащий все рёбра графа и являющийся деревом. Остовное дерево называется минимальным, если сумма весов входящих в него рёбер минимально возможная.

Граф связен и не содержит петель и кратных рёбер. Кроме того, гарантируется, что после каждого запроса веса всех рёбер неотрицательны.

Формат ввода
В первой строке входного файла содержатся два целых числа n и m  — количество вершин и рёбер графа соответственно (2 ≤ n ≤ 500, 1 ≤ m ≤ 50 000). В следующих m строках содержится по три целых числа u, v, w. Это значит, что в графе есть ребро веса w, соединяющее вершины u и v (1 ≤ u, v ≤ n, 1 ≤ w ≤ 10).

В следующей строке содержится целое число q — количество запросов (1 ≤ q ≤ 500). В следующих q строках содержится по одному целому числу id (1 ≤ id ≤ m). Это значит, что требуется уменьшить на единицу вес ребра id. Рёбра нумеруются с единицы в порядке следования во входном файле.

Формат вывода
Выведите q чисел, разделённых пробелами или переводами строки — веса минимального остовного дерева после выполнения каждого запроса.

*/

#include <bits/stdc++.h>

struct Edge {
  bool operator<(const Edge& other) {
    return w < other.w;
  }

  size_t s;
  size_t f;
  size_t w;
};

std::vector<size_t> parent;
std::vector<size_t> rank;

void MakeSet(size_t x) {
  parent[x] = x;
  rank[x] = 0;
}

int FindSet(size_t x) {
  if (x != parent[x]) {
    parent[x] = FindSet(parent[x]);
  }
  return parent[x];
}

void Link(size_t x, size_t y) {
  if (rank[x] > rank[y]) {
    parent[y] = x;
  } else {
    parent[x] = y;
    if (rank[x] == rank[y]) {
      ++rank[y];
    }
  }
}

void UniteSets(size_t x, size_t y) {
  Link(FindSet(x), FindSet(y));
}

int FindMstWeight(size_t n, std::vector<Edge> g) {
  for (size_t i = 1; i <= n; ++i) {
    MakeSet(i);
  }

  sort(g.begin(), g.end());

  size_t mstW = 0;

  for (auto e : g) {
    size_t v = e.s;
    size_t u = e.f;

    if (FindSet(v) != FindSet(u)) {
      mstW += e.w;
      UniteSets(v, u);
    }
  }

  return mstW;
}

int main() {
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;

  std::vector<Edge> g;

  for (int j = 0; j < m; ++j) {
    size_t v = 0;
    size_t u = 0;
    size_t w = 0;
    std::cin >> v >> u >> w;

    g.push_back({v, u, w});
  }

  size_t q = 0;
  std::cin >> q;

  parent.resize(n + 1);
  rank.resize(n + 1);

  for (size_t i = 0; i < q; ++i) {
    size_t id = 0;
    std::cin >> id;

    --g[id - 1].w;
    std::cout << FindMstWeight(n, g) << std::endl;
  }
}
