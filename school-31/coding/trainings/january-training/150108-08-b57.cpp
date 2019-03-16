#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("shooting.in");
ofstream cout("shooting.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

struct prt {
    int res, ind;
    bool is;
    prt(int a = 0, int b = 0) {
        res = a;
        ind = b;
        is = false;
    }
};

bool comp(prt a, prt b) {
    if (a.res > b.res) {
        return true;
    }
    if (a.res == b.res && a.is) {
        return true;
    }
    return false;
}

vector<prt> a;

int main() {
    int n;
    int mx = 0;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].res;
        a[i].ind = i;
        if (a[i].res > mx) {
            mx = a[i].res;
        }

    }
    for (int i = 1; i < n - 1; ++i) {
        if (a[i].res % 5 == 0 && a[i].res % 10 != 0 && a[i - 1].res == mx && a[i].res > a[i + 1].res) {
            a[i].is = true;
        }
    }
    sort(a.begin(), a.end(), comp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].is == true) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
