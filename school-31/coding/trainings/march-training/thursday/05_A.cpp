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
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;
const int Max = 100000;

struct pass {
    int a, b, ind, place;
    pass(int param1 = 0, int param2 = 0, int param3 = 0, int param4 = 0) {
        a = param1;
        b = param2;
        ind = param3;
        place = param4;
    }
};

struct event {
    int stop, type, ind;
    event (int param1 = 0, int param2 = 0, int param3 = 0) {
        stop = param1;
        type = param2;
        ind = param3;
    }
};

bool comp(event a, event b) {
    return (a.stop < b.stop ||
            a.stop == b.stop && a.type < b.type);
}

int Len, Amt;
vector<event> e;
vector<pass> p;
vector<long long> usd, sgt;
vector<int> blk, lft, rgt;

void init(int n) {
    Len = (int)sqrt(n);
    Amt = n / Len + 1;
    usd.assign(n + 1, 0);
    blk.resize(n + 1);
    lft.assign(Amt + 1, n);
    rgt.assign(Amt + 1, 1);
    sgt.assign(Amt + 1, 0);
    for (int i = 1; i <= n; ++i) {
        blk[i] = 1 + i / Len;
        lft[blk[i]] = min(lft[blk[i]], i);
        rgt[blk[i]] = max(rgt[blk[i]], i);
    }
}

void inc(int ind) {
    usd[ind] = 1;
    ++sgt[blk[ind]];
}

void dec(int ind) {
    usd[ind] = 0;
    --sgt[blk[ind]];
}

long long sum(int l, int r) {
    long long res = 0;
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; ++i) {
            res += usd[i];
        }
    } else {
        res += sum(l, rgt[blk[l]]);
        res += sum(lft[blk[r]], r);
        for (int j = blk[l] + 1; j <= blk[r] - 1; ++j) {
            res += sgt[j];
        }
    }
    return res;
}

int main() {
    freopen("taxibus.in", "r", stdin);
    freopen("taxibus.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int n, a, b, m, k;
    long long ans;

    cin >> n;
    p.resize(n + 1);
    e.resize(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        p[i] = pass(a, b, i);
        e[i] = event(a, 1, i);
        e[i + n] = event(b, 0, i);
    }
    sort(e.begin() + 1, e.end(), comp);
    m = n;
    k = 1;
    ans = 0;
    init(n);
    for (int t = 1; t <= 2 * n; ++t) {
        int i = e[t].ind;
        if (e[t].type == 1) {
            p[i].place = m;
            inc(m);
            ++k;
            --m;
        } else {
           dec(p[i].place);
           ans += sum(1, p[i].place);
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << p[i].place << " ";
    }
    cout << "\n";

    return 0;
}
