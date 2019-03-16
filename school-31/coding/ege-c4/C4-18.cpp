#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<string, int> res;
vector< pair<int, string> > out;

int main() {
  int n;
  string name;
  cin >> n;
  getline(cin, name);
  for (int i = 0; i < n; ++i) {
    getline(cin, name);
    ++res[name];
  }
  for (map<string, int>::iterator it = res.begin(); it != res.end(); ++it) {
    out.push_back(make_pair(-it->second, it->first));
  }
  sort(out.begin(), out.end());
  for (int i = 0; i < (int)out.size(); ++i) {
    cout << out[i].second << "\n";
  }
  return 0;
}