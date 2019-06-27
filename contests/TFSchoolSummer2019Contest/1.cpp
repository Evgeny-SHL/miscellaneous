/*



*/

#include <bits/stdc++.h>

int main() {
  size_t n = 0;
  std::cin >> n;

  ssize_t d = 100;
  size_t min = d;
  for (size_t i = 0; i < n; ++i) {
    size_t x = 0;
    std::cin >> x;
    d += x;
    if (d < 0) {
      d *= -1;
    }
    if (d < min) {
      min = d;
    }
  }
  std::cout << min << std::endl;
}
