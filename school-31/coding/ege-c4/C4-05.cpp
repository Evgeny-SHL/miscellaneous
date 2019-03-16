#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector< pair<string, string> > best;

int main() {
  ifstream cin("input.txt");
  ios_base::sync_with_stdio(0);
  string nam, fam, prev;
  long long a, b, c, sum;
  long long cur = 0;
  for (long long i = 0; cin >> nam >> fam >> a >> b >> c; ++i) {
    sum = a + b + c;
    if ((i == 0) || (sum > cur)) {
      cur = sum;
      best.clear();
    }
    if (sum == cur) {
      best.push_back(make_pair(fam, nam));
    }
    prev = fam + " " + nam;
  }
  sort(best.begin(), best.end());
  cout << best.size() << "\n";
  for (long long i = 0; i < best.size(); ++i) {
    cout << best[i].second << " " << best[i].first << " " << cur << "\n";
  }
  return 0;
}