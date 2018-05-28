/*

Задача 5
В колл-центр Tinkoff.ru иногда приходят очень сложные запросы, которые требуют разбирательства специалистов высшего уровня. Сейчас поступило N сложных запросов разного типа и на работе находятся M специалистов высшего уровня. Запросы приходят по разным продуктам: мобильный оператор, инвестиции, дебетовые карты и тд. У руководителя группы есть матрица навыков: какой специалист обладает базой знаний по каким продуктам. Так как запросы очень сложные, каждый сотрудник в определенный момент времени занимается не более чем одним запросом, при этом для решения одного запроса всегда достаточно ровно одного сотрудника. Помогите руководителю группы определить максимальное число запросов, которые сотрудники могут взять сейчас в работу при оптимальной загрузке.

Входные данные
Первая строка содержит числа NN и MM ( 1 \leqslant N, M \leqslant 100).(1⩽N,M⩽100). Следующие MM строк содержат NN чисел: 00 или 11 (матрица навыков специалистов). Если в строке ii и столбце jj стоит 0,0, то сотрудник ii не может выполнить запрос под номером j,j, если стоит 1,1, то может.
Результат работы
Одно число, максимальное количество запросов, которое можно начать выполнять.

*/

#include <iostream>
#include <vector>
#include <limits>

const int Infinity = std::numeric_limits<int>::max();

int main()
{
  int numberOfRows = 0;
  int numberOfColumns = 0;
  std::cin >> numberOfColumns >> numberOfRows;
  std::vector<std::vector<int>> matrix( numberOfRows + 1, std::vector<int>( numberOfColumns + 1 ) );
  for( int rowIndex = 1; rowIndex <= numberOfRows; ++rowIndex ) {
    for( int columnIndex = 1; columnIndex <= numberOfColumns; ++columnIndex ) {
      std::cin >> matrix[rowIndex][columnIndex];
       matrix[rowIndex][columnIndex] *= -1;
    }
  }
  std::vector<int> rowPotential( numberOfRows + 1 );
  std::vector<int> columnPotential( numberOfColumns + 1 );
  std::vector<int> matching( numberOfColumns + 1 );
  std::vector<int> pointOfMin( numberOfColumns + 1 );
  for( int rowIndex = 1; rowIndex <= numberOfRows; ++rowIndex ) {
    matching[0] = rowIndex;
    int vacantColumn = 0;
    std::vector<int> auxiliaryMin( numberOfColumns + 1, Infinity );
    std::vector<char> used( numberOfColumns + 1, false );
    do {
      used[vacantColumn] = true;
      int newRow = matching[vacantColumn];
      int minInNewRow = Infinity;
      int pointOfMinInNewRow;
      for( int columnIndex = 1; columnIndex <= numberOfColumns; ++columnIndex )
        if( !used[columnIndex] ) {
          int currentValue = matrix[newRow][columnIndex] - rowPotential[newRow] - columnPotential[columnIndex];
          if( currentValue < auxiliaryMin[columnIndex] ) {
            auxiliaryMin[columnIndex] = currentValue;
            pointOfMin[columnIndex] = vacantColumn;
          }
          if( auxiliaryMin[columnIndex] < minInNewRow ) {
            minInNewRow = auxiliaryMin[columnIndex];
            pointOfMinInNewRow = columnIndex;
          }
        }
        for( int columnIndex = 0; columnIndex <= numberOfColumns; ++columnIndex ) {
          if( used[columnIndex] ) {
            rowPotential[matching[columnIndex]] += minInNewRow;
            columnPotential[columnIndex] -= minInNewRow;
          } else {
            auxiliaryMin[columnIndex] -= minInNewRow;
          }
        }
      vacantColumn = pointOfMinInNewRow;
    } while( matching[vacantColumn] != 0 );
    do {
      int pointOfMinInNewRow = pointOfMin[vacantColumn];
      matching[vacantColumn] = matching[pointOfMinInNewRow];
      vacantColumn = pointOfMinInNewRow;
    } while( vacantColumn != 0 );
  }
  int minCost = columnPotential[0];
  std::cout << minCost << std::endl;
}
