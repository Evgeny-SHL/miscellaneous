#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

template <class T> T inline sqr(T x) {
        return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

const int N = 16;
const int inf = 1e9 + 10;
int a[N];
bool good[N][N];
int d[(1 << N)][N];

void add(int& x, int y)
{
    x = min(x + y, inf);
}

int main()
{
    freopen("perm.in", "r", stdin);
#ifndef HOME
    freopen("perm.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    forn (i, n)
        cin >> a[i];
    sort(a, a + n);
    forn (i, n)
        forn (j, n)
            good[i][j] = (i != j) && (__gcd(a[i], a[j]) >= k);
    m--;
    forn (msk, (1 << n))
        forn (f, n)
            if ((1 << f) & msk) {
                if ((1 << f) == msk) {
                    d[msk][f] = 1;
                    continue;
                }
                forn (nex, n)
                    if (((1 << nex) & msk) && good[f][nex])
                        add(d[msk][f], d[msk ^ (1 << f)][nex]);
            }
    int msk = (1 << n) - 1;
    vi ans;
    while (msk){
        bool was = false;
        forn (i, n)
        if (ans.empty() || __gcd(a[i], ans.back()) >= k)
        {
        if (d[msk][i] > m){
            was = 1;
            ans.pb(a[i]);
            msk ^= (1 << i);
            break;
        }
        else
            m -= d[msk][i];
        }
        if (!was) { puts("-1"); return 0;}
    }
    for (int x: ans)
        cout << x << " ";

	for (int i = 0; i < n; ++i) {
		cout << i << " " << d[1 << n][i];
	}

    return 0;
}
