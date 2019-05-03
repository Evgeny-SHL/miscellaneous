/*

Ошибка

Вы обслуживаете сайт и отслеживаете возникающие проблемы. Клиент получил ошибку после того, как попытался добавить свой пост в систему. Вы хотите понять на каком из серверов эта ошибка произошла.

Есть n серверов, на i-й из них приходится ai процентов запросов, из которых bi процентов завершаются с ошибкой. Для каждого сервера найдите вероятность того, что ошибка произошла именно на нём.

Формат ввода
В первой строке входного файла содержится одно целое число n (1 ≤n≤ 100) — количество серверов.

В каждой из следующих n строк содержится два целых числа ai bi (0 ≤ ai, bi ≤ 100) — вероятность того что запрос пойдет на i-й сервер в процентах и вероятность того что на i-м сервере случится ошибка в процентах.

Гарантируется, что сумма всех ai равна 100 и ошибка в системе может произойти.

Формат вывода
Выведите n строк. В каждой строке должно находиться одно вещественное число (0 ≤ pi ≤ 1) — вероятность, что ошибка произошла на соответствующем сервере.

Абсолютная или относительная погрешность каждого из ответов не должна превышать 10-9.

*/

#include <iomanip>
#include <iostream>
#include <vector>

int main()
{
  int serversCount = 0;
  std::cin >> serversCount;

  long long errorProbability = 0;
  std::vector<long long> probabilities{};
  for( int serverId = 0; serverId < serversCount; ++serverId ) {
    int serverProbability = 0;
    int serverErrorProbability = 0;
    std::cin >> serverProbability >> serverErrorProbability;
    probabilities.push_back( serverProbability * serverErrorProbability );
    errorProbability += probabilities.back();
  }

  std::cout << std::setprecision(12);

  for( int serverId = 0; serverId < serversCount; ++serverId ) {
    std::cout << static_cast<double>( probabilities[serverId] ) / errorProbability << std::endl;
  }

  return 0;
}
