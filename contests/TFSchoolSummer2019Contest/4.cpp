/*

Задача 4
Перед Женей лежит белый лист размера N \times MN×M клеток. Часть клеток Женя закрасила синим, а оставшуюся часть она хочет расчертить на прямоугольники. Прямоугольник должен содержать только белые клетки, грани прямоугольника проходят по граням клеток. На какое наименьшее число прямоугольников она может расчертить свой лист?

Входные данные
Первая строка содержит NN MM (1 \leqslant N, M \leqslant 121⩽N,M⩽12). Следующие NN строк содержат по MM чисел в каждой: 11 если клетка синяя, 00 если белая
Результат работы
Одно число -− минимальное число прямоугольников

Примеры
Входные данные
2 2
1 0
1 0
Результат работы
1

*/

#include <bits/stdc++.h>

size_t n = 0;
size_t m = 0;

using Sheet = std::vector<std::vector<bool>>;
Sheet isWhite;

bool IsWhite(size_t topIndex,
             size_t bottomIndex,
             size_t leftIndex,
             size_t rightIndex) {
  for (size_t i = topIndex; i <= bottomIndex; ++i) {
    for (size_t j = leftIndex; j <= rightIndex; ++j) {
      if (!isWhite[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void CutMaxRectangle(size_t rowIndex, size_t columnIndex) {
  size_t maxRow = rowIndex;
  size_t maxColumn = columnIndex;
  size_t maxArea = 1;
  for (size_t i = rowIndex; i < n; ++i) {
    for (size_t j = columnIndex; j < m; ++j) {
      if (IsWhite(rowIndex, i, columnIndex, j)) {
        size_t area = (i - rowIndex + 1) * (j - columnIndex + 1);
        if (area > maxArea) {
          maxArea = area;
          maxRow = i;
          maxColumn = j;
        }
      }
    }
  }

  for (size_t i = rowIndex; i <= maxRow; ++i) {
    for (size_t j = columnIndex; j <= maxColumn; ++j) {
      isWhite[i][j] = false;
    }
  }
}

int main() {
  std::cin >> n >> m;

  isWhite.assign(n, std::vector<bool>(m, false));

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      size_t code = 0;
      std::cin >> code;
      isWhite[i][j] = code == 0;
    }
  }

  size_t rectangleCount = 0;

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      if (isWhite[i][j]) {
        CutMaxRectangle(i, j);
        ++rectangleCount;
      }
    }
  }

  std::cout << rectangleCount << std::endl;
}
