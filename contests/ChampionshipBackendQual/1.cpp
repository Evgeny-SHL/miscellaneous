/*

A. Будильники
Ограничение времени	2 секунды
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Работа в большинстве IT-компаний имеет много преимуществ: нет дресс-кода, можно иногда поработать удалённо, классные и умные коллеги и, конечно же, свободный график! Однако свободный график и возможность работать удалённо требуют большой силы воли.
Программист Алексей любит работать по ночам и не любит приходить на работу поздно. Чтобы точно проснуться с утра, Алексей каждый вечер заводит
N
 будильников на своём телефоне. Каждый будильник устроен таким образом, что он звонит каждые
X
 минут с того момента времени, на который его завели. Например, если будильник был заведён на момент времени
t
i
, то он будет звонить в моменты времени
t
i
,
t
i
+
X
,
t
i
+
2
⋅
X
 и так далее. При этом если какие-то два будильника начинают звонить в один момент времени, то отображается только один из них.
Известно, что прежде чем проснуться, Алексей каждое утро слушает ровно
K
 будильников, после чего просыпается. Определите момент времени, когда Алексей проснётся.

Формат ввода
Первая строка содержит три целых числа
N
,
X
 и
K
 (
1
≤
N
≤
1
0
5
,
1
≤
X
,
K
≤
1
0
9
) — количество будильников, периодичность звонков и количество будильников, которое нужно отключить, чтобы Алексей проснулся.
Вторая строка содержит
N
 целых чисел
t
1
,
t
2
,
…
,
t
N
 (
1
≤
t
i
≤
1
0
9
) — моменты времени на которые были заведены будильники.

Формат вывода
Выведите одно число — момент времени, когда Алексей проснётся.

*/

#include <bits/stdc++.h>

using Alarms = std::unordered_map<size_t, std::set<size_t>>;

size_t Count(size_t t, size_t x, const Alarms& a) {
  size_t n = 0;
  for (auto&& [r, s] : a) {
    if (s.empty()) {
      continue;
    }
    size_t start = *s.begin();
    if (start <= t) {
      n += 1 + (t - start) / x;
    }
  }
  return n;
}

int main() {
  size_t n = 0;
  size_t x = 0;
  size_t k = 0;
  std::cin >> n >> x >> k;

  Alarms a;

  for (size_t i = 0; i < n; ++i) {
    size_t t = 0;
    std::cin >> t;
    a[t % x].insert(t);
  }

  size_t l = 1;
  size_t r = -1;

  while (l < r - 1) {
    size_t m = l + (r - l) / 2;
    if (Count(m, x, a) < k) {
      l = m;
    } else {
      r = m;
    }
  }

  std::cout << r << std::endl;
}
