#include <fstream>
#include <vector>
#include <algorithm>
#define segm vector<pair<int, int> >
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int> g;
vector<pair<int, int> > w;
segm st;
segm fn;

int maxc(int r, int c, int n, int b, char v, int m, segm st, segm fn) {
    cout << r << " " << c << " " << v << " " << m << '\n';
    cout.flush();
    int mn = n + 1, mx = 0;
    for (int i = 1; i <= b; ++i) {
        if (v == 'u' || v == 'd') {
            if (w[i].second != c) {
                continue;
            }
            mn = min(mn, w[i].first + 1);
            mx = max(mx, w[i].first - 1);
        } else {
            if (w[i].first != r) {
                continue;
            }
            mn = min(mn, w[i].second + 1);
            mx = max(mx, w[i].second - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (v == 'u' && st[i].first == fn[i].first) {
            int r1 = st[i].first;
            int c1 = st[i].second;
            int c2 = fn[i].second;
            if (r < r1 && r1 < mx && min(c1, c2) <= c && c <= max(c1, c2)) {
                mx = st[i].first - 1;
            }
        } else if (v == 'l' && st[i].second == fn[i].second) {
            int c1 = st[i].second;
            int r1 = st[i].first;
            int r2 = fn[i].first;
            if (mn < c1 && c1 < c && min(r1, r2) <= r && r <= max(r1, r2)) {
                mn = st[i].second + 1;
            }
        } else if (v == 'r' && st[i].second == fn[i].second) {
            int c1 = st[i].second;
            int r1 = st[i].first;
            int r2 = fn[i].first;
            if (c < c1 && c1 < mx && min(r1, r2) <= r && r <= max(r1, r2)) {
                mx = st[i].second - 1;
            }
        } else if (v == 'd' && st[i].first == fn[i].first) {
            int r1 = st[i].first;
            int c1 = st[i].second;
            int c2 = fn[i].second;
            if (mn < r1 && r1 < r && min(c1, c2) <= c && c <= max(c1, c2)) {
                mn = st[i].first + 1;
            }
        }
    }
    ++m;
    st.push_back(make_pair(r, c));
    if (v == 'u') {
        fn.push_back(make_pair(mx, c));
    } else if (v == 'l') {
        fn.push_back(make_pair(r, mn));
    } else if (v == 'r') {
        fn.push_back(make_pair(r, mx));
    } else if (v == 'd') {
        fn.push_back(make_pair(mn, c));
    }

    int l;
    if (v == 'u') {
        l = mx - r + 1;
    } else if (v == 'd') {
        l = r - mn + 1;
    } else if (v == 'l') {
        l = c - mn + 1;
    } else {
        l = mx - c + 1;
    }

    cout << '\n';
    cout << r << " " << c << '\n';
    r = fn[m - 1].first;
    c = fn[m - 1].second;
    cout << r << " " << c << '\n';
    if (c >= 1 && c <= n && r >= 1 && c <= n) {
        if (v == 'u' || v == 'd') {
            bool f1 = c > 1;
            bool f2 = c < n;
            if (c > 1) {
                for (int i = 1; i <= b; ++i) {
                    if (w[i].first == r && w[i].second == c - 1) {
                        f1 = false;
                    }
                }
               if (f1) {
                    for (int i = 0; i < m; ++i) {
                        if (min(st[i].first, fn[i].second) <= r && r <= max(st[i].first, fn[i].first) &&
                        min(st[i].second, fn[i].second) <= c - 1 && c - 1 <= max(st[i].second, fn[i].second)) {
                            f1 = false;
                        }
                    }
                }
            } else if (c < n) {
                for (int i = 1; i <= b; ++i) {
                    if (w[i].first == r && w[i].second == c + 1) {
                        f2 = false;
                    }
                }
                if (f2) {
                    for (int i = 0; i < m; ++i) {
                        if (min(st[i].first, fn[i].second) <= r && r <= max(st[i].first, fn[i].first) &&
                        min(st[i].second, fn[i].second) <= c + 1 && c + 1 <= max(st[i].second, fn[i].second)) {
                            f2 = false;
                        }
                    }
                }
            }
            if (f1 && f2) {
                l += max(maxc(r, c - 1, n, b, 'l', m, st, fn), maxc(r, c + 1, n, b, 'r', m, st, fn));
            } else if (f1) {
                l += maxc(r, c - 1, n, b, 'l', m, st, fn);
            } else if (f2) {
                l += maxc(r, c + 1, n, b, 'r', m, st, fn);
            }
        } else {
            bool f1 = r > 1;
            bool f2 = r < n;
            if (r > 1) {
                for (int i = 1; i <= b; ++i) {
                    if (w[i].first == r - 1 && w[i].second == c) {
                        f1 = false;
                    }
                }
                if (f1) {
                    for (int i = 0; i < m; ++i) {
                        if (min(st[i].first, fn[i].second) <= r - 1 && r - 1 <= max(st[i].first, fn[i].first) &&
                        min(st[i].second, fn[i].second) <= c && c <= max(st[i].second, fn[i].second)) {
                            f1 = false;
                        }
                    }
                }
            } else if (r < n) {
                for (int i = 1; i <= b; ++i) {
                    if (w[i].first == r + 1 && w[i].second == c) {
                        f2 = false;
                    }
                }
                if (f2) {
                    for (int i = 0; i < m; ++i) {
                        if (min(st[i].first, fn[i].second) <= r + 1 && r + 1 <= max(st[i].first, fn[i].first) &&
                        min(st[i].second, fn[i].second) <= c && c <= max(st[i].second, fn[i].second)) {
                            f2 = false;
                        }
                    }
                }
            }
            if (f1 && f2) {
                l += max(maxc(r - 1, c, n, b, 'd', m, st, fn), maxc(r + 1, c, n, b, 'u', m, st, fn));
            } else if (f1) {
                l += maxc(r - 1, c, n, b, 'd', m, st, fn);
            } else if (f2) {
                l += maxc(r + 1, c, n, b, 'u', m, st, fn);
            }
        }
    }
    return l;
}

int main() {

    int n, b;
    char r, c;

    cin >> n >> b;

    w.resize(b + 1);
    for (int i = 1; i <= b; ++i) {
        cin >> r >> c;
        w[i] = make_pair(int(r - 'A') + 1, int(c - '0'));
    }

    st.resize(0);
    fn.resize(0);

    int m = max(maxc(1, 1, n, b, 'r', 0, st, fn), maxc(1, 1, n, b, 'd', 0, st, fn));

    cout << m << '\n';

    return 0;
}
