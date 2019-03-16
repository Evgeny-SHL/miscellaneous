#include <fstream>
#include <cmath>
using namespace std;

ifstream cin("lawn.in");
ofstream cout("lawn.out");

int main() {
    long long x1, y1, x2, y2, x3, y3, r;
    long long ans = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r;
    long long rr = r * r;
    if (x1 > x2) {
        long long v = x1;
        x1 = x2;
        x2 = v;
    }
    if (y1 > y2) {
        long long v = y1;
        y1 = y2;
        y2 = v;
    }
    for (long long x = max(x3 - r, x1); x <= min(x3 + r, x2); ++x) {
     //   cout << ans << '\n';
        long long y_up = min(y2, y3 + (long long)sqrt(rr - (x - x3) * (x - x3)));
        long long y_down = max(y1, y3 - (long long)sqrt(rr - (x - x3) * (x - x3)));
     //   cout << x << " " << y_up << " " << y_down << '\n';
        ans += max(y_up - y_down + 1, (long long)0);
    }
    cout << ans << '\n';
    return 0;
}
