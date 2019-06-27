/*

B. Спортивный турнир
Ограничение времени	2 секунды
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Пока Маша была в отпуске, её коллеги организовали турнир по шахматам по олимпийской системе. За отдыхом Маша не обращала особого внимания на эту затею, так что она еле может вспомнить, кто с кем играл (про порядок игры даже речи не идёт). Внезапно Маше пришла в голову мысль, что неплохо бы привезти из отпуска сувенир победителю турнира. Маша не знает, кто победил в финальной игре, но сможет без труда вычислить, кто в нём играл, если только она правильно запомнила играющие пары. Помогите ей проверить, так ли это, и вывести возможных кандидатов в победители.
Формат ввода
В первой строке находится целое число
k
,
2
≤
k
≤
1
6
, — количество этапов турнира. В последующих
n
=
2
k
−
1
 строках — по две фамилии игроков (латинскими заглавными буквами) через пробел. Все фамилии уникальны, однофамильцев среди коллег нет.
Формат вывода
«NO SOLUTION» (без кавычек) — если Маша неправильно запомнила игры и по этой сетке нельзя получить турнир по олимпийской системе. Если турнирная сетка возможна, выведите две фамилии в одной строке — фамилии кандидатов на первое место (порядок не важен).

*/

#include <bits/stdc++.h>

class Graph {
 private:
 public:
  void AddEdge(const std::string &name1, const std::string &name2) {
    ++l[name1][name2];
    ++l[name2][name1];
  }

  bool IsConnected() {
    std::unordered_map<std::string, bool> visited;
    for (auto&&[n, v] : l) {
      TraverseGraph(n, visited);
      break;
    }

    for (auto&&[n, v] : l) {
      if (!visited[n]) {
        return false;
      }
    }

    return true;
  }

  bool HasCycle() {
    std::unordered_map<std::string, bool> visited;
    for (auto&&[n, v] : l) {
      return TraverseCycle(n, visited, "");
    }
    return false;
  }

 private:
  void TraverseGraph(const std::string &i,
                     std::unordered_map<std::string, bool> &v) {
    v[i] = true;
    for (auto&&[n, d] : l[i]) {
      if (!v[n]) {
        TraverseGraph(n, v);
      }
    }
  }

  bool TraverseCycle(const std::string &i,
                     std::unordered_map<std::string, bool> &v,
                     const std::string &p) {
    v[i] = true;
    size_t c = 0;
    for (auto&&[n, d] : l[i]) {
      if (n == p) {
        ++c;
      } else if (v[n]) {
        return true;
      } else if (!v[n]) {
        if (TraverseCycle(n, v, i)) {
          return true;
        }
      }
    }
    return c > 1;
  }

 private:
  std::unordered_map<std::string, std::unordered_map<std::string, size_t>> l;
};

size_t Two(size_t p) {
  size_t r = 1;
  for (size_t i = 0; i < p; ++i) {
    r *= 2;
  }
  return r;
}

int main() {
  size_t k = 0;
  std::cin >> k;

  std::unordered_map<std::string, size_t> m;

  size_t n = 1;
  for (size_t i = 0; i < k; ++i) {
    n *= 2;
  }
  --n;

  Graph g;

  std::vector<std::pair<std::string, std::string>> p;

  for (size_t i = 0; i < n; ++i) {
    std::string n1;
    std::string n2;
    std::cin >> n1 >> n2;
    if (n1 == n2) {
      std::cout << "NO SOLUTION" << std::endl;
      return 0;
    }
    ++m[n1];
    ++m[n2];
    g.AddEdge(n1, n2);
    p.emplace_back(n1, n2);
  }

  std::map<std::pair<size_t, size_t>, size_t> e;

  for (auto&& [n1, n2] : p) {
    if (m[n1] < m[n2]) {
      ++e[{m[n1], m[n2]}];
    } else {
      ++e[{m[n2], m[n1]}];
    }
  }

  bool f = true;
  for (size_t i = 1; i < k; ++i) {
    for (size_t j = i + 1; j < k; ++j) {
      f = f && e[{i, j}] == Two(k - j);
    }
  }

  for (size_t i = 1; i < k; ++i) {
    f = f && e[{i, k}] == 2;
    f = f && e[{i, i}] == 0;
  }

  f = f && e[{k, k}] == 1;

  if (!f) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  std::vector<size_t> v(k + 1, 0);

  for (auto&&[n, c] : m) {
    ++v[c];
  }

  size_t t = 2;

  if (v[k] != t) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  for (size_t i = k - 1; i > 0; --i) {
    if (v[i] != t) {
      std::cout << "NO SOLUTION" << std::endl;
      return 0;
    }
    t *= 2;
  }

  if (!g.IsConnected()) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  if (g.HasCycle()) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  for (auto&&[n, c] : m) {
    if (c == k) {
      std::cout << n << " ";
    }
  }
}
