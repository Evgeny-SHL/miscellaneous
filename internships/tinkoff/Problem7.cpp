/*

Задача 7
В некоторой компании у каждого человека, кроме мистера X,X, есть ровно один руководитель. Сотрудниками 11-го уровня назовем всех, у кого руководитель мистер XX. Сотрудниками 22-го уровня тех, у кого руководители сотрудники 11-го уровня и т.д. Вам дано дерево иерархий этой компании, определите уровень каждого сотрудника (уровень мистера XX положим за 00).

Входные данные
Первая строка содержит NN – число сотрудников в компании. Далее следует N - 1N−1 строка, задающая для каждого сотрудника его руководителя (кроме мистера XX) в следующем формате: имя сотрудника и имя руководителя, через пробел.
Результат работы
Программа должна вывести всех сотрудников и их уровень построчно в лексикографическом порядке в формате: имя" "уровень (см. пример).

*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

class SlavesList {
public:
  SlavesList() = default;

  std::vector<std::string> Slaves{};
  int Level = 0;
};

std::map<std::string, SlavesList> hierarchy{};

void FindLevels(const std::string& name) {
  for(auto& slave : hierarchy[name].Slaves) {
    hierarchy[slave].Level = hierarchy[name].Level + 1;
    FindLevels(slave);
  }
}

int main() {
  int stuffCount = 0;
  std::cin >> stuffCount;

  hierarchy["X"] = SlavesList();

  std::string slave{};
  std::string master{};

  for(int i = 0; i < stuffCount - 1; ++i) {
    std::cin >> slave >> master;
    hierarchy[master].Slaves.push_back(slave);
  }

  FindLevels("X");

  for(auto& employee : hierarchy) {
    std::cout << employee.first << " " << employee.second.Level << std::endl;
  }

  return 0;
}
