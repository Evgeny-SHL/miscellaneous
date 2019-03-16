#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("space.in");
ofstream cout("space.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

vector< vector<bool> > g;

int main() {
    int n, k, x, y;
    cin >> n >> k;
    int x_l = 1;
    int y_d = 1;
    int x_r = k;
    int y_r = k;
    int ans = 0;
    int ost = n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x > k || y > k) {
            g[x][y] = true;
            t_x[x] = true;
            t_y[y] = true;
        } else {
            ost -= n;
        }
    }
    for (int x = 50; x > k; --x) {
        if (t_x[x]) {
            x_next = x;
            break;
        }
    }
    for (int y = 1; y <= 50; ++y) {
        if (t_y[y]) {
            y_next = y;
            break;
        }
    }
    ans += y_next - 1;
    ans += x_next - k;
    x_r = x_next;
    y_d = y_next;
    x_l = x_r - k + 1;
    x_u = y_d + k - 1;
    for (int y = y_next; y < y_next + k; ++y) {
        for (int x = k + 1; x <= x_next; ++x) {
            if (g[x][y]) {
                g[x][y] = false;
                --ost;
            }
        }
    }

    return 0;
}
