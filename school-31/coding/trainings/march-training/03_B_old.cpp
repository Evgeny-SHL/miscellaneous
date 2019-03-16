
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

const double Eps = 1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;
const int Max = 100000;

int freq[Max + 1];
int cnt[Max + 1];
int ans[Max + 1];
bool used[Max + 1];
int ind[Max + 1];


int main() {
    freopen("theatre.in", "r", stdin);
    freopen("theatre.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i <= Max; ++i) {
        freq[i] = 0;
        cnt[i] = 0;
        ans[i] = 0;
        used[i] = false;
        ind[i] = 0;
    }

    int n, m, k;

    cin >> n >> m;
    cnt[0] = n;
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> ind[j];
            if (!used[ind[j]]) {
                --cnt[freq[ind[j]]];
                ++freq[ind[j]];
                ++cnt[freq[ind[j]]];
            }
        }
        for (int p = 1; p <= n; ++p) {
            if (!used[p]) {
                if (cnt[freq[p]] == 1) {
                    ans[p] = i;
                }
            }
        }
        for (int p = 1; p <= n; ++p) {
            if (ans[p] == i) {
                --cnt[freq[p]];
                freq[p] = -1;
                used[p] = true;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
