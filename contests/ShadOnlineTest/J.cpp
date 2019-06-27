/*Есть кучка из n камней. Два игрока играют в игру. Каждый игрок на своем ходу может взять любое количество камней от L до R. Проигрывает тот, кто не может сделать ход. Определите, кто выиграет при оптимальной игре обоих.



Шахматы

Дано шахматное поле n × n. На поле расположено m коней. Определить, какое количество клеток не заняты и не находятся под боем.

Формат ввода
Первая строка входного файла содержит два числа n и m (1 ≤ n ≤ 1000, 1 ≤ m ≤ 50000) – размеры поля и количество коней соответственно. Следующие m строк содержат пары координат xi, yi (1 ≤ xi, yi ≤ n) – координаты очередного коня.

Формат вывода
Выведите одно число – ответ на задачу.

*/

#include <bits/stdc++.h>

bool check(int x, int y, int n) {
  return 1 <= std::min(x, y) && std::max(x, y) <= n;
}

int main() {
  std::array<std::pair<int, int>, 8> d{
      std::make_pair(-2, 1),
      std::make_pair(-2, -1),
      std::make_pair(2, -1),
      std::make_pair(2, 1),
      std::make_pair(1, -2),
      std::make_pair(1, 2),
      std::make_pair(-1, -2),
      std::make_pair(-1, 2)
  };

  std::set<std::pair<int, int>> dam;
  std::set<std::pair<int, int>> hor;

  int n = 0;
  int m = 0;

  std::cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int x = 0;
    int y = 0;
    std::cin >> x >> y;
    hor.emplace(x, y);
    for (auto& p : d) {
      int dx = x + p.first;
      int dy = y + p.second;
      if (check(dx, dy, n)) {
        dam.emplace(dx, dy);
      }
    }
  }

  for (auto& p : hor) {
    dam.erase(p);
  }

  std::cout << n * n - dam.size() - hor.size() << std::endl;
}
