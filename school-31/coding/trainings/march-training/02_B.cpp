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

struct participant {
    int year, pnts, ind;
    participant(int p1 = 0, int p2 = 0, int p3 = 0) {
        year = p1;
        pnts = p2;
        ind = p3;
    }
};

bool comp(participant a, participant b) {
    return (a.pnts > b.pnts);
}
int func(int m94, int m95, int m96, int a, int b, int c) {
    return abs(a - m94) + abs(b - m95) + abs(c - m96);
}

vector<participant> part;
vector<int> cnt4, cnt5, cnt6;

int main() {
    freopen("school.in", "r", stdin);
    freopen("school.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int k, a, b, c, n, best, f, delt;
    int im94, im95, im96;

    scanf("%d", &k);
    for (int t = 1; t <= k; ++t) {
        part.clear();
        cnt4.clear();
        cnt5.clear();
        cnt6.clear();
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d", &n);
        part.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &part[i].year, &part[i].pnts);
            part[i].ind = i;
        }
        sort(part.begin() + 1, part.end(), comp);
        cnt4.assign(n + 1, 0);
        cnt5.assign(n + 1, 0);
        cnt6.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cnt4[i] = cnt4[i - 1];
            cnt5[i] = cnt5[i - 1];
            cnt6[i] = cnt6[i - 1];
            if (part[i].year == 1994) {
                ++cnt4[i];
            } else if (part[i].year == 1995) {
                ++cnt5[i];
            } else {
                ++cnt6[i];
            }
        }
    /*  for (int i = 1; i <= n; ++i) {
            cerr << part[i].year << " " << part[i].pnts << "\n";
        }
        for (int i = 1; i <= n; ++i) {
            cerr << cnt6[i] << " \n"[i == n];
        }
        for (int i = 1; i <= n; ++i) {
            cerr << cnt5[i] << " \n"[i == n];
        }
        for (int i = 1; i <= n; ++i) {
            cerr << cnt4[i] << " \n"[i == n];
        }
    */  f = 0;
        im94 = im95 = im96 = 0;
        // case 1996
        best = (int)sInf;
        for (int i = n; i >= 3; --i) {
            if (cnt6[i] > 0 && cnt5[i - 1] > 0 && cnt4[i - 2] > 0 &&
                cnt4[i - 2] + cnt5[i - 1] + cnt6[i] >= a + b + c) {
                delt = abs(c - cnt6[i]);
                if (delt < best) {
                    best = delt;
                    im96 = i;
                }
            }
        }
        f += best;
        // case 1995
        best = (int)sInf;
        for (int i = im96 - 1; i >= 2; --i) {
            if (cnt5[i] > 0 && cnt4[i - 1] > 0 &&
                cnt4[i - 1] + cnt5[i] + cnt6[im96] >= a + b + c) {
                delt = abs(b - cnt5[i]);
                if (delt < best) {
                    best = delt;
                    im95 = i;
                }
            }
        }
        f += best;
        // case 1994
        best = (int)sInf;
        for (int i = im95 - 1; i >= 1; --i) {
            if (cnt4[i] > 0 &&
                cnt4[i] + cnt5[im95] + cnt6[im96] == a + b + c) {
                delt = abs(a - cnt4[i]);
                if (delt < best) {
                    best = delt;
                    im94 = i;
                }
            }
        }
        f += best;
    //  cerr << im94 << " " << im95 << " " << im96 << "\n";
    //  cerr << cnt4[im94] << " " << cnt5[im95] << " " << cnt6[im96] << "\n";
        if (cnt4[im94] == 0 || cnt5[im95] == 0 || cnt6[im96] == 0 ||
            cnt4[im94] + cnt5[im95] + cnt6[im96] != a + b + c) {
            printf("-1\n");
        } else {
            assert(im94 < im95 && im95 < im96);
            printf("%d %d %d %d\n", func(cnt4[im94], cnt5[im95], cnt6[im96], a , b, c), cnt4[im94], cnt5[im96], cnt6[im96]);
        }
    }

    return 0;
}
