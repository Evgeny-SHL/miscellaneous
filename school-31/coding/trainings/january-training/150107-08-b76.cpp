#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
//#include <iostream>
using namespace std;

ifstream cin("wheel.in");
ofstream cout("wheel.out");

/*struct sect {
    int pr, ind;
    sect(int a = 0, ind = 0) {
        pr = a;
        ind = b;
    }
}*/

/*bool comp(sect a, sect b) {
    return (a.pr > b.pr);
}*/

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

vector<int> f;

int main() {
    int n, a, b, k, mx = 0;
    cin >> n;
    f.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i]/*.pr*/;
     //   f[i].ind = i;
    }
 //   sort(f.begin(), f.end(), comp);
    cin >> a >> b >> k;
    for (int v = a; v <= b; ++v) {
    //    cout << mx << '\n';
        mx = max(mx, f[(v / k) % n]);
     //   cout << mx << '\n';
        mx = max(mx, f[((long long)1e9 * n - v / k) % n]);
     //   cout << mx << '\n';
    }
    cout << mx << '\n';
    return 0;
}
