#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    long long x, y;
    point(long long a, long long b) {
        x = a;
        y = b;
    }
};

ifstream cin("triangle.in");
ofstream cout("triangle.out");

vector<point> pt;

long long len(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long s_tr(point a, point b, point c) {
    return abs((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x));
}

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    pt.resize(n + 1, point(0, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> pt[i].x >> pt[i].y;
    }
    for (int i = 1; i <= n - 2; ++i) {
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
    }
    cout << ans << '\n';
    return 0;
}
