/*

Робот

Робот расположен в точке (0,0). Робот движется по спирали в следующем порядке: (0,0), (0,−1), (1,−1), (1,0), (1,1), (0,1), (−1,1), (−1,0), (−1,−1), (−1,−2), …

PIC

Определить, где будет находиться робот через N шагов.

Формат ввода
Единственная строка входного файла содержит одно целое неотрицательное число
N (0≤N≤1012) – количество сделанных шагов.

Формат вывода
Выведите два числа – координаты клетки, в которой окажется робот через N шагов.

*/

#include <bits/stdc++.h>

int main() {
  long long n;
  std::cin >> n;

  if (n == 0) {
    std::cout << "0 0" << std::endl;
    return 0;
  } else if (n == 1) {
    std::cout << "0 -1" << std::endl;
    return 0;
  }

  long long m = (1ll + std::sqrt(1ll + 4ll * n)) / 2 + 0.0001;

  long long x = 0;
  long long y = 0;
  if (m % 2 == 1) {
    x = (1 - m) / 2;
    y = (m - 1) / 2;
  } else {
    x = m / 2;
    y = -m / 2;
  }

  long long s = m - 1;
  long long prev = m * (m - 1);
  long long t = m % 2 == 1 ? 0 : 2;
  while (true) {
    long long cur = prev;
    switch (t) {
      case 0:s += 1;
        y -= s;
        cur += s;
        break;
      case 1:x += s;
        cur += s;
        break;
      case 2:s += 1;
        y += s;
        cur += s;
        break;
      case 3:x -= s;
        cur += s;
        break;
    }
    if (cur >= n) {
      long long q = cur - n;
      switch (t) {
        case 0:y += q;
          break;
        case 1:x -= q;
          break;
        case 2:y -= q;
          break;
        case 3:x += q;
          break;
      }
      break;
    }
    t = (t + 1) % 4;
    prev = cur;
  }

  std::cout << x << " " << y << std::endl;

}
