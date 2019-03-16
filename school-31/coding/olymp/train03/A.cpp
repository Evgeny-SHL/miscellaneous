#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct human {
    long long a, b, c, d;
    human(long long x = 0, long long y = 0, long long z = 0, long long w = 0) {
        a = x;
        b = y;
        c = z;
        d = w;
    }
};

bool comp1(human a, human b) {
    if (a.c < b.c) {
        return true;
    }
    if (a.c == b.c && a.d < b.d) {
        return true;
    }
    return false;
}

bool comp2(human a, human b) {
   /* if (a.b > a.a) {
        return false;
    }
    if (a.a > b.a) {
        return true;
    }
    if (a.a == b.a && a.b > b.b) {
        return true;
    }
    return false;*/
    if (a.a + b.b > a.b + b.a) {
        return true;
    }
    if (a.a + b.b == a.b + b.a && a.a > b.a) {
        return true;
    }
    return false;
    /*
    if (a.a <= a.b && b.a <= b.b) {
        if ((a.a - a.b) > (b.a - b.b)) {
            return true;
        } else if ((a.a - a.b) == (b.a - b.b) && a.b > b.b) {
            return true;
        }
        return false;
    } else if (a.a <= a.b && b.a >= b.b) {
        return false;
    } else if (a.a >= a.b && b.a < b.b) {
        return true;
    } else if (a.a >= a.b && b.a >= b.b) {
        if ((a.a - a.b) > (b.a - b.b)) {
            return true;
        } else if ((a.a - a.b) == (b.a - b.b) && a.a > b.a) {
            return true;
        }
        return false;
    }

    return false;*/
}

ifstream cin("tram.in");
ofstream cout("tram.out");

vector<human> h;
vector<human> cur;

int main() {
    long long n, m, p;
    cin >> n >> m >> p;
    h.resize(n);
    for (long long i = 0; i < n; ++i) {
        cin >> h[i].a >> h[i].b >> h[i].c >> h[i].d;
    }
    sort(h.begin(), h.end(), comp1);
   // for (int i = 0; i < n; ++i) {
  //      cout<< h[i].a <<h[i].b<< h[i].c <<h[i].d << '\n';
  //  }
  //  cout << '\n';
    long long ans = 0;
    for (long long i = 1; i <= p; ++i) {
        cur.clear();
        /*for (int r = 0; r < n; ++r) {
            if (h[r].c > i) {
                break;
            }
            if (h[r].d > i) {
                cur.push_back(h[r]);
            }
        }*/
        for (long long j = 0; j < n; ++j) {
            if (h[j].c <= i && h[j].d > i) {
                cur.push_back(h[j]);
            }
        }
        sort(cur.begin(), cur.end(), comp2);
        long long k = cur.size();
      /*  cout << i << '\n';
       for (int j = 0; j < k; ++j) {
        cout<< cur[j].a<< " "  <<cur[j].b<< " " << cur[j].c <<" " << cur[j].d << '\n';
    }
    cout << '\n';*/
        int t = m;
        for (long long j = 0; j < k; ++j) {
            if (cur[j].a >= cur[j].b && t > 0) {
                ans += cur[j].a;
                --t;
            } else {
                ans += cur[j].b;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
