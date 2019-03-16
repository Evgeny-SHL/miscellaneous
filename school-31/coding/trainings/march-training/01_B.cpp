#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

const int Max = 1000;

vector<long long> dp;

int main() {
    freopen("grasshopper.in", "r", stdin);
    freopen("grasshopper.out", "w", stdout);
    srand(time(0));
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int n;
    long long k;
    bool bad, found, big;
    cin >> n >> k;
    if ((double)k > pow(Phi, (double)n + 1.0)) {
		 cout << "Impossible\n";
		 return 0;
    }
    found = false;
    for (int mask = 0; mask < (1 << n); ++mask) {
        bitset<Max> way(mask);
        if (way[0] == 0 || way[n - 1] == 0) {
            continue;
        }
        bad = false;
        if (k > 0) {
            for (int i = 0; i < n - 1; ++i) {
                if (way[i] == 0 && way[i + 1] == 0) {
                    bad = true;
                    break;
                }
            }
        }
        if (bad) {
            continue;
        }
        dp.resize(n);
        dp[0] = 1;
        dp[1] = dp[0] * way[0];
        big = false;
        for (int i = 2; i < n; ++i) {
            dp[i] = way[i - 1] * dp[i - 1] + way[i - 2] * dp[i - 2];
            if (dp[i] < 0) {
                big = true;
                break;
            }
        }
        if (!big && dp[n - 1] == k) {
            for (int i = 0; i < n; ++i) {
                cout << way[i] << " ";
            }
            cout << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Impossible\n";
    }

    return 0;
}
