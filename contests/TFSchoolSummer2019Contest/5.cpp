/*

Задача 5
В колл-центр Tinkoff.ru иногда приходят очень сложные запросы, которые требуют разбирательства специалистов высшего уровня. Сейчас поступило N сложных запросов разного типа и на работе находятся M специалистов высшего уровня. Запросы приходят по разным продуктам: мобильный оператор, инвестиции, дебетовые карты и тд. У руководителя группы есть матрица навыков: какой специалист обладает базой знаний по каким продуктам. Так как запросы очень сложные, каждый сотрудник в определенный момент времени занимается не более чем одним запросом, при этом для решения одного запроса всегда достаточно ровно одного сотрудника. Помогите руководителю группы определить максимальное число запросов, которые сотрудники могут взять сейчас в работу при оптимальной загрузке.

Входные данные
Первая строка содержит числа NN и MM ( 1 \leqslant N, M \leqslant 100).(1⩽N,M⩽100). Следующие MM строк содержат NN чисел: 00 или 11 (матрица навыков специалистов). Если в строке ii и столбце jj стоит 0,0, то сотрудник ii не может выполнить запрос под номером j,j, если стоит 1,1, то может.
Результат работы
Одно число, максимальное количество запросов, которое можно начать выполнять.

Примеры
Входные данные
2 2
1 0
1 0
Результат работы
1

*/

#include <bits/stdc++.h>


int main() {
  const int Infinity = std::numeric_limits<int>::max();

  size_t rowCount = 0;
  size_t columnCount = 0;
  std::cin >> columnCount >> rowCount;

  size_t totalColumnCount = std::max(columnCount, rowCount);

  std::vector<std::vector<int>> skills(rowCount + 1, std::vector<int>(totalColumnCount + 1, 0));
  for (size_t rowIndex = 1; rowIndex <= rowCount; ++rowIndex) {
    for (size_t columnIndex = 1; columnIndex <= columnCount; ++columnIndex) {
      std::cin >> skills[rowIndex][columnIndex];
      skills[rowIndex][columnIndex] *= -1;
    }
  }

  columnCount = totalColumnCount;

  std::vector<int> rowPotential(rowCount + 1);
  std::vector<int> columnPotential(columnCount + 1);
  std::vector<size_t> columnIndexToRowIndex(columnCount + 1);
  std::vector<size_t> columnIndexToMinRowIndex(columnCount + 1);

  for (size_t rowIndex = 1; rowIndex <= rowCount; ++rowIndex) {
    columnIndexToRowIndex[0] = rowIndex;
    size_t vacantColumn = 0;
    std::vector<int> auxiliaryMin(columnCount + 1, Infinity);
    std::vector<bool> isUsed(columnCount + 1, false);

    do {
      isUsed[vacantColumn] = true;
      size_t newRowIndex = columnIndexToRowIndex[vacantColumn];
      int minInNewRow = Infinity;
      size_t minColumnInNewRow = 0;

      for (size_t columnIndex = 1; columnIndex <= columnCount; ++columnIndex) {
        if (!isUsed[columnIndex]) {
          int newValue = skills[newRowIndex][columnIndex] - rowPotential[newRowIndex] - columnPotential[columnIndex];
          if (newValue < auxiliaryMin[columnIndex]) {
            auxiliaryMin[columnIndex] = newValue;
            columnIndexToMinRowIndex[columnIndex] = vacantColumn;
          }
          if (auxiliaryMin[columnIndex] < minInNewRow) {
            minInNewRow = auxiliaryMin[columnIndex];
            minColumnInNewRow = columnIndex;
          }
        }
      }

      for (size_t columnIndex = 0; columnIndex <= columnCount; ++columnIndex) {
        if (isUsed[columnIndex]) {
          rowPotential[columnIndexToRowIndex[columnIndex]] += minInNewRow;
          columnPotential[columnIndex] -= minInNewRow;
        } else {
          auxiliaryMin[columnIndex] -= minInNewRow;
        }
      }
      vacantColumn = minColumnInNewRow;
    } while (columnIndexToRowIndex[vacantColumn] != 0);

    do {
      size_t minRowInVacantColumn = columnIndexToMinRowIndex[vacantColumn];
      columnIndexToRowIndex[vacantColumn] = columnIndexToRowIndex[minRowInVacantColumn];
      vacantColumn = minRowInVacantColumn;
    } while (vacantColumn != 0);
  }

  std::cout << columnPotential[0] << std::endl;
}
