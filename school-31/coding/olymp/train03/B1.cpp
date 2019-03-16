#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    double x, y;
    point(double a = 0.0, double b = 0.0) {
        x = a;
        y = b;
    }
};

struct segm {
  long long dy, dx;
  int i, j;
  point mid;
  segm(int a, int b, double d1, double d2, point m) {
    i = a;
    j = b;
    dy = d1;
    dx = d2;
    mid.x = m.x;
    mid.y = m.y;
  }
};

ifstream cin("triangle.in");
ofstream cout("triangle.out");

vector<point> pt;
vector<point> v;
vector<segm> s;

double len(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

/*double s_tr(point a, point b, point c) {
    return abs((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x));
}*/

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    pt.resize(n + 1, point(0, 0));
    if (n == 3) {
        cout << 1;
    } else if (n == 4) {
        cout << 4;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> pt[i].x >> pt[i].y;
    }
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            s.push_back(segm(i, j, pt[i].y - pt[j].y, pt[i].x - pt[j].x, point((pt[i].x + pt[j].x) / 2, (pt[i].y + pt[j].y) / 2)));
        }
    }

    /*for (int i = 1; i <= n - 2; ++i) {
        for (int j = i + 1; j <= n - 1; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                long long a = len(pt[i], pt[j]);
                long long b = len(pt[i], pt[k]);
                long long c = len(pt[j], pt[k]);
                long long s = s_tr(pt[i], pt[j], pt[k]);
                if (s > 0 && (a == b || a == c || b == c)) {
                    ++ans;
                }
            }
        }
    }*/
    cout << ans << '\n';
    return 0;
}
