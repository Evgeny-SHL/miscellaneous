/*

Библиотека

Коля очень любит читать, и он ходил бы в библиотеку каждый день. К вечеру он остаётся довольным, только если прочитал ровно на одну книгу больше, чем вчера. Однако, к сожалению, библиотека не работает по субботам и воскресеньям. Поэтому Коля ходит в неё каждый рабочий день и берёт там за раз k книг — больше нельзя по правилам. Однако, Колю радует, что брать новые k книг можно, даже если ты не отдал какие-то книги из взятых ранее. Также Колю радует, что в его домашней библиотеке есть запас из m книг.

Вам известно, какой сегодня день недели. Коля недавно встал и задался целью прочитать сегодня ровно одну книгу. Насколько долго Коля может оставаться довольным, если будет ходить в библиотеку каждый раз, когда это возможно, начиная с сегодняшнего дня? Можно считать, что запас книг в библиотеке бесконечен.

Формат ввода
В первой строке входного файла даны три целых числа k, m, d — лимит на количество книг, которые можно взять в библиотеке в день, количество книг дома у Коли и сегодняшний день недели (1 ≤ k ≤ 109, 0 ≤ m ≤ 109, 1 ≤ d ≤ 7). Суббота и воскресенье обозначаются числами 6 и 7.

Формат вывода
Выведите одно число — максимальное количество дней в периоде, в течение которого Коля каждый день сможет читать столько книг, чтобы оставаться довольным.

*/

#include <algorithm>
#include <iostream>

bool IsWeekend( int day ) {
  return day == 6 || day == 7;
}

bool Update( long long& books, long long& demand, int& day, long long& max, long long limit ) {
  if( !IsWeekend( day )) {
    books += limit;
  }
  books -= demand;
  if( books < 0 ) {
    return false;
  }
  ++max;
  day = 1 + day % 7;
  ++demand;
  return true;
}

long long Correct( long long limit, long long books, int day ) {
  long long max = 0;
  long long demand = 1;
  while( Update( books, demand, day, max, limit ) ) {
  }
  return max;
}

int main() {
  long long limit;
  long long books;
  int day;

  std::cin >> limit >> books >> day;

  // std::cout << Correct( limit, books, day ) << std::endl;

  long long demand = 1;
  long long max = 0;

  do {
    while( day != 1 ) {
      if ( !Update( books, demand, day, max, limit ) ) {
        std::cout << max << std::endl;
        return 0;
      }
    }

    while( books + limit - 7 * demand - 21 >= 0 ) {
      books += 5 * limit - 7 * demand - 21;
      demand += 7;
      max += 7;
      continue;
    }
  } while( Update( books, demand, day, max, limit ) );

  std::cout << max << std::endl;
}
