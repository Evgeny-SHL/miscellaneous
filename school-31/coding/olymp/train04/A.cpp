#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("game.in");
ofstream cout("game.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int mx_a = 0, mx_b = m / k;
    for (int x = 0; x <= m; ++x) {
        for (int b = 0; b <= x / k; ++b) {
            int a = x - b * k;
            if (a < k) {
                if (a > mx_a) {
                    mx_a = a;
                }
            }
        }
    }
    cout << (mx_a + mx_b) * n << '\n';
    return 0;
}
