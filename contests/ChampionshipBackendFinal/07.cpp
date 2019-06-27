/*



*/

#include <bits/stdc++.h>

class Dsu {
 public:
  void UniteSets(size_t x, size_t y) {
    Link(FindSet(x), FindSet(y));
  }

  bool IsConnected(size_t x, size_t y) {
    return FindSet(x) == FindSet(y);
  }

 private:
  int FindSet(size_t x) {
    LazyInit(x);
    if (x != Parents[x]) {
      Parents[x] = FindSet(Parents[x]);
    }
    return Parents[x];
  }

  void Link(size_t x, size_t y) {
    if (Ranks[x] > Ranks[y]) {
      Parents[y] = x;
    } else {
      Parents[x] = y;
      if (Ranks[x] == Ranks[y]) {
        ++Ranks[y];
      }
    }
  }

  void LazyInit(size_t x) {
    if (Parents[x] == 0) {
      Parents[x] = x;
    }
  }

 private:
  std::unordered_map<size_t, size_t> Parents;
  std::unordered_map<size_t, size_t> Ranks;
};


int main() {
  size_t n = 0;
  std::cin >> n;

  Dsu dsu;

  for (size_t i = 0; i < n; ++i) {
    size_t x = 0;
    size_t y = 0;
    std::cin >> x >> y;
    dsu.UniteSets(x, y);
  }

  size_t q = 0;
  std::cin >> q;

  for (size_t i = 0; i < q; ++i) {
    size_t x = 0;
    size_t k = 0;
    std::cin >> x >> k;

    std::vector<size_t> ys;
    for (size_t j = 0; j < k; ++j) {
      size_t y = 0;
      std::cin >> y;
      if (dsu.IsConnected(x, y)) {
        ys.push_back(y);
      }
    }

    std::cout << ys.size();
    for (auto&& y : ys) {
      std::cout << " " << y;
    }
    std::cout << std::endl;
  }
}
