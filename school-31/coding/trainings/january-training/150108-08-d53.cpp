#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("house.in");
ofstream cout("house.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);
const double EPS = 1e-6;

struct line {
    double a, b, c;
    line(double x = 0, double y = 0, double z = 0) {
        a = x;
        b = y;
        c = z;
    }
};

bool comp(line l1, line l2) {
    return (l1.c < l2.c - EPS);
}

vector<line> l, ox, oy;

int main() {
    int n;
    double x1, y1, x2, y2;
    cin >> n;
    l.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        l[i].a = y2 - y1;
        l[i].b = x1 - x2;
        l[i].c = y1 * (x2 - x1) - x1 * (y2 - y1);
        if (abs(l[i].a) < EPS) {
            ox.push_back(l[i]);
        } else if (abs(l[i].b) < EPS) {
            oy.push_back(l[i]);
        }
    }
    sort(ox.begin(), ox.end(), comp);
    sort(oy.begin(), oy.end(), comp);
    sort(l.begin(), l.end(), comp);
    int m = ox.size();
    int k = oy.size();
    double x = 0.0, y = 0.0;
    if (m > 0 || k > 0) {
        if (m > 0) {
            if (m % 2 == 1) {
                x = -ox[m / 2].c / ox[m / 2].b;
            } else {
                x = -(ox[m / 2].c + ox[m / 2 - 1].c) / ox[m / 2].b;
            }
        }
        if (k > 0) {
            if (k % 2 == 1) {
                y = -oy[k / 2].c / oy[k / 2].a;
            } else {
                y = -(oy[k / 2].c + oy[k / 2 - 1].c) / oy[k / 2].a;
            }
        }
    } else {
        y = 0;
        if (n % 2 == 1) {
            x = -ox[m / 2].c / ox[m / 2].b;
        } else {
            x = -(ox[m / 2].c + ox[m / 2 - 1].c) / ox[m / 2].b;
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << x << " " << y << '\n';
    return 0;
}
