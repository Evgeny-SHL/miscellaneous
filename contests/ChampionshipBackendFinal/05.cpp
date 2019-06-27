/*



*/

#include <bits/stdc++.h>

struct Interval {
  size_t s = 0;
  size_t f = 0;
  size_t i = 0;

  bool operator<(const Interval &that) const {
    return f < that.f
        || (f == that.f && s < that.s)
        || (f == that.f && s == that.s && i < that.i);
  }
};

int main() {
  size_t n = 0;
  std::cin >> n;

  std::vector<Interval> v;

  for (size_t i = 0; i < n; ++i) {
    size_t a = 0;
    size_t x = 0;
    std::cin >> a >> x;
    v.push_back({a, a + x - 1, i});
  }

  std::sort(v.begin(), v.end());

  std::vector<size_t> dpExc(n, 0);
  std::vector<size_t> dpInc(n, 0);

  std::vector<ssize_t> parPrv(n, -1);
  std::vector<ssize_t> parInd(n, -1);

  dpExc[0] = 0;
  dpInc[0] = v[0].f - v[0].s + 1;

  parPrv[0] = -1;
  parInd[0] = 0;

  for (size_t i = 1; i < n; ++i) {
    dpExc[i] = std::max(dpExc[i - 1], dpInc[i - 1]);

    auto ub = std::lower_bound(v.begin(), v.end(), Interval{0, v[i].s, 0});
    ssize_t j = ub - v.begin();

    if (j > 0) {
      dpInc[i] = std::max(dpInc[j - 1], dpExc[j - 1]) + v[i].f - v[i].s + 1;
    } else {
      dpInc[i] = v[i].f - v[i].s + 1;
    }

    if (dpExc[i] >= dpInc[i]) {
      parPrv[i] = i - 1;
    } else {
      parPrv[i] = j - 1;
      parInd[i] = v[i].i;
    }
  }

  std::cout << std::max(dpExc[n - 1], dpInc[n - 1]) << std::endl;

  ssize_t k = n - 1;
  if (parInd[k] != -1) {
    std::cout << parInd[k] << " ";
  }
  while (k != -1) {
    k = parPrv[k];
    if (k != -1 && parInd[k] != -1) {
      std::cout << parInd[k] << " ";
    }
  }

  std::cout << std::endl;
}
