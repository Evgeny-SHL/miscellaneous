/*

Тимбилдинг

Тимбилдинг — весёлое сплочающее мероприятие. Коллеги активно участвуют в конкурсах, квестах, вместе преодолевают игровые трудности. Подчас люди так увлекаются, что реорганизовать их для какой-то новой активности довольно сложно. Прямо сейчас ведущему нужно разбить всех коллег на две команды так, чтобы каждые два человека в одной команде хорошо знали друг друга — и это непростая задача.

Вам дан граф, в котором каждому человеку сопоставлена ровно одна вершина. Ребро (u, v) означает, что коллега u хорошо знает коллегу v (и в то же время коллега v хорошо знает коллегу u). Проверьте, можно ли разбить вершины графа на два множества требуемым образом, и, если это возможно, выведите любое подходящее разбиение.

Формат ввода
В первой строке даны два целых числа n и m (2 ≤ n ≤ 5000, 0 ≤ m ≤ 200000) — число вершин и число рёбер в графе.

В следующих m строках даны описания рёбер — пары целых чисел a b (1 ≤ a, b ≤ n, a ≠ b), означающих наличие ребра между вершинами a и b.

Гарантируется, что каждая пара вершин соединена не более чем одним ребром, и что никакая вершина не соединена с собой.

Формат вывода
Если разбить вершины требуемым образом нельзя, выведите -1.

Иначе в первой строке выведите число k (1 ≤ k < n) — количество вершин в одной из частей разбиения.

В следующей строке выведите k чисел — вершины из этой части разбиения.

В следующей строке выведите n - k чисел — вершины из второй части разбиения.

Каждая вершина должна принадлежать ровно одной из этих частей.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using Graph = std::vector<std::set<int>>;
using Group = std::set<int>;

bool DivideGraph( const Graph& graph, Group& groupA, Group& groupB, Group& others ) {
  int nodesCount = graph.size() - 1;
  int edgesCount = 0;
  for( int i = 1; i < nodesCount; ++i ) {
    edgesCount += graph[i].size();
  }

  if ( edgesCount == 0 ) {
    return false;
  } else if ( edgesCount == nodesCount * ( nodesCount - 1 ) / 2 ) {
    groupA.insert( 1 );
    for( int i = 2; i <= nodesCount; ++i ) {
      groupB.insert( i );
    }
    return true;
  }

  int leaderA = 1;
  int leaderB = 2;

  for( int from = 1; from < edgesCount; ++from ) {
    for( auto to : graph[from] ) {
      if( from > to ) {
        continue;
      }
      if( from == leaderA && to == leaderB ) {
        leaderB = 1 + leaderB % nodesCount;
        if( leaderB == 1) {
          leaderA = 1 + leaderA % nodesCount;
        }
      }
    }
  }

  groupA.insert( leaderA );
  groupB.insert( leaderB );

  for( int i = 1; i <= nodesCount; ++i ) {
    if ( i == leaderA || i == leaderB ) {
      continue;
    }

    bool hasA = graph[leaderA].find( i ) != graph[leaderA].end();
    bool hasB = graph[leaderB].find( i ) != graph[leaderB].end();

    if( !hasA && !hasB ) {
      return false;
    } else if ( hasA && !hasB ) {
      groupA.insert( i );
    } else if( !hasA && hasB ) {
      groupB.insert( i );
    } else {
      others.insert( i );
    }
  }

  if ( others.size() == 1 ) {
    groupA.insert( *others.begin() );
    others.clear();
  }



  return true;
}

int main() {

  int nodesCount = 0;
  int edgesCount = 0;
  std::cin >> nodesCount >> edgesCount;

  Graph graph( nodesCount + 1 );

  for( int i = 0; i < edgesCount; ++i ) {
    int from = 0;
    int to = 0;
    std::cin >> from >> to;
    graph[from].insert(to);
    graph[to].insert(from);
  }

  Group groupA{};
  Group groupB{};
  Group others{};

  while( true ) {
    Group a{};
    Group b{};
    Group o{};
    bool isDivided = DivideGraph( graph, a, b, o );
    if ( !isDivided ) {
      std::cout << -1 << std::endl;
      return 0;
    }
    for( auto i : a ) {
      groupA.insert( i );
    }
    for( auto i : b ) {
      groupB.insert( i );
    }
    if ( others.size() == 0 ) {
      break;
    }

    std::map<int, int> m;
    int n = 1;
    for( auto i : o ) {
      m[i] = n;
      ++n;
    }
    Graph g( n + 1 );
    for( auto i : o ) {
      for( auto j : graph[i] ) {
        if ( o.find( j ) == o.end() ) {
          continue;
        }
        g[m[i]].insert(m[j]);
        g[m[j]].insert(m[i]);
      }
    }
    graph = g;
  }

  std::cout << groupA.size() << std::endl;
  for( auto node : groupA ) {
    std::cout << node << " ";
  }
  std::cout << std::endl;
  for( auto node : groupB ) {
    std::cout << node << " ";
  }
  std::cout << std::endl;
  return 0;

  std::cout << -1 << std::endl;

  return 0;
}
