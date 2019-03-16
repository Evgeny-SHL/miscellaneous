#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = (double)1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<int> blc, zrs;

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    string seq;
    int m, last;
    long long ans;

    cin >> seq;
    m = seq.length();
    seq = "*" + seq;
    blc.resize(m + 2);
    blc[0] = 0;
    zrs.push_back(0);
    for (int i = 1; i <= m; ++i) {
        if (seq[i] == '(') {
            blc[i] = blc[i - 1] + 1;
        } else {
            blc[i] = blc[i - 1] - 1;
        }
        if (blc[i] == 0) {
            zrs.push_back(i);
        }
    }
    blc[m + 1] = 0;
    zrs.push_back(m + 1);
    ans = 0;
    last = zrs.size() - 1;
    for (int i = m + 1; i >= 1; --i) {
        if (blc[i] == 0) {
            --last;
        }
        blc[i] = blc[i - 1] + 1;
        ans = ans + (m + 1 - zrs[last]);
    }
    cout << ans << "\n";

    return 0;
}
