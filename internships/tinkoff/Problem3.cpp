/*

Задача 3
Аналитики Tinkoff.ru выехали на корпоратив и сняли для праздника пляж. На пляже стоит ряд пронумерованных шезлонгов с одинаковыми расстояниями между ними и аналитики в случайном порядке занимают места. Чтобы ничего такого не случилось, аналитики решили разбиться на группы таким образом, чтобы каждый аналитик находился в группе хотя бы из 2 человек. После этого они считают следующую метрику: для каждого аналитика находят другого ближайшего аналитика из его группы и если он находится слева берут модуль разности между номерами их шезлонгов, после чего полученные данные суммируют. Какое минимальное значение метрики они смогут получить?

Входные данные
Первая строка содержит число NN – количество аналитиков на выезде (2 \leqslant N \leqslant 100).(2⩽N⩽100).
Вторая строка содержит NN чисел – номера шезлонгов, где расположились аналитики ((до 1000).1000).
Результат работы
Выведите значение описанной метрики.

*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int analystsCount = 0;
  std::cin >> analystsCount;

  std::vector<int> chaises(analystsCount);
  for(int i = 0; i < analystsCount; ++i) {
    std::cin >> chaises[i];
  }
  std::sort(chaises.begin(), chaises.end());

  std::vector<int> subAnswers(analystsCount);
  subAnswers[0] = 1001;
  subAnswers[1] = chaises[1] - chaises[0];
  for(int i = 2; i < analystsCount; ++i) {
    subAnswers[i] = chaises[i] - chaises[i - 1] + std::min(subAnswers[i - 1], subAnswers[i - 2]);
  }

  std::cout << subAnswers[analystsCount - 1] << std::endl;

  return 0;
}
