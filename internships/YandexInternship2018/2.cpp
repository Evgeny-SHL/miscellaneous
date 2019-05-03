/*

Встречи

Чтобы не мешать коллегам на рабочем месте громкими обсуждениями, ребята назначают встречи на определенное время и бронируют переговорки. При бронировании нужно указать дату и время встречи, её длительность и список участников. Если у кого-то из участников получается две встречи в один и тот же момент времени, то в бронировании будет отказано с указанием списка людей, у которых время встречи пересекается с другими встречами. Вам необходимо реализовать прототип такой системы.

Формат ввода
В первой строке входного файла содержится одно число n (1 ≤ n ≤ 1000) — число запросов.

В следующих n строках содержатся запросы по одному в строке. Запросы бывают двух типов:

APPOINT day time duration k names1 names2 ... namesk
PRINT day name
day — номер дня в 2018 году (1 ≤ day ≤ 365)

time — время встречи, строка в формате HH:MM (08 ≤ HH ≤ 21, 00 ≤ MM ≤ 59)

duration — длительность встречи в минутах (15 ≤ duration ≤ 120)

k — число участников встречи (1 ≤ k ≤ 10)

namesi, name — имена участников, строки, состоящие из маленьких латинских букв (1 ≤ |name| ≤ 20). У всех коллег уникальные имена. Кроме того гарантируется, что среди участников одной встречи ни одно имя не встречается дважды.

Формат вывода
Если удалось назначить встречу (первый тип запросов), выведите OK.

Иначе выведите в первой строке FAIL, а в следующей строке через пробел список имен участников, для которых время встречи пересекается с другими встречами, в том порядке, в котором имена были даны в запросе.

Для второго типа запросов выведите для данного дня и участника список всех событий на данный момент в этот день в хронологическом порядке, по одному в строке, в формате

HH:MM duration names1 names2 … namesk

где имена участников следуют в том же порядке, что и в исходном описании встречи. Если событий в данный день для этого человека нет, то ничего выводить не нужно.

*/

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Meeting {
 public:
  Meeting( int day, int time = 0, int duration = 0, const std::vector<std::string>& names = std::vector<std::string>{} ) :
      Day( day ), Time( time ), Duration( duration ), Names( names )
  {
  }

  bool operator<( const Meeting& other ) const {
    return Day < other.Day ||  Day == other.Day && Time < other.Time;
  }

  int Day = 0;
  int Time = 0;
  int Duration = 0;
  std::vector<std::string> Names{};
};

int GetNumber( char digit ) {
  return static_cast<int>( digit - '0' );
}

int GetDigit( int number ) {
  return static_cast<char>( number + '0' );
}

int GetMinutes( std::string time ) {
  return 60 * 10 * GetNumber( time[0] ) + 60 * GetNumber( time[1] ) + 10 * GetNumber( time[3] ) + GetNumber( time[4] );
}

std::string GetTime( int time ) {
  std::string minutes = std::to_string( time % 60 );
  std::string hours = std::to_string( time / 60 );
  if (minutes.length() == 0) {
    minutes = "00";
  }
  if (minutes.length() == 1) {
    minutes = "0" + minutes;
  }
  if (hours.length() == 0) {
    hours = "00";
  }
  if (hours.length() == 1) {
    hours = "0" + hours;
  }
  return hours + ":" + minutes;
}

int main() {
  std::unordered_map<std::string, std::set<Meeting>> schedule;

  int requestCount = 0;
  std::cin >> requestCount;

  std::string type = "";
  int day = 0;
  std::string stime = "";
  int time = 0;
  int duration = 0;
  int namesCount = 0;
  std::vector<std::string> names{};
  std::string name = "";
  std::vector<std::string> busy{};

  for( int requestId = 0; requestId < requestCount; ++requestId ) {
    std::cin >> type;

    if( type == "APPOINT" ) {
      std::cin >> day >> stime >> duration >> namesCount;
      int time = GetMinutes( stime );

      for( int i = 0; i < namesCount; ++i) {
        std::cin >> name;
        names.push_back( name );

        auto begin = schedule[name].upper_bound( Meeting( day, time - 120 ) );
        auto end = schedule[name].lower_bound( Meeting( day, time + duration ) );

        for( auto iter = begin; iter != end; ++iter ) {
          auto meeting = *iter;

          if( !( day == meeting.Day && ( meeting.Time + meeting.Duration <= time || time + duration <= meeting.Time ) ) ) {
            busy.push_back( name );
            break;
          }
        }
      }
      if( busy.size() > 0 ) {
        std::cout << "FAIL" << std::endl;

        for( auto name : busy ) {
          std::cout << name << " ";
        }
        std::cout << std::endl;
      } else {
        std::cout << "OK" << std::endl;

        auto meeting = Meeting( day, time, duration, names );
        for( auto name: names ) {
          schedule[name].insert( meeting );
        }
      }

      names.clear();
      busy.clear();
    } else {
      std::cin >> day >> name;

      auto begin = schedule[name].lower_bound( Meeting( day ) );
      auto end = schedule[name].lower_bound( Meeting( day + 1 ) );

      for( auto iter = begin; iter != end; ++iter ) {
        auto meeting = *iter;

        std::cout << GetTime( meeting.Time ) << " " << meeting.Duration << " ";
        for( auto name : meeting.Names ) {
          std::cout << name << " ";
        }
        std::cout << std::endl;
      }
    }
  }

  return 0;
}
