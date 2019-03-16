#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream cin("elephants.in");
ofstream cout("elephants.out");

vector< string > a;

void srch(int n, int m) {

    int r1, c1, r2, c2, r3, c3, r4, c4;
    r1 = r2 = c1 = c2 = r3 = r4 = c3 = c4 = 0;
    for (r1 = 1; r1 <= n; ++r1) {
        for (c1 = 0; c1 < m; ++c1) {
            if (a[r1][c1] != 'S') {
                continue;
            }
            for (r2 = 1; r2 <= n; ++r2) {
                for (c2 = 0; c2 < m; ++c2) {
                    if (a[r2][c2] != 'L' || abs(r2 - r1) != abs(c2 - c1)) {
                        continue;
                    }
                    for (r3 = 1; r3 <= n; ++r3) {
                        for (c3 = 0; c3 < m; ++c3) {
                            if (a[r3][c3] != 'O' || abs(r3 - r2) != abs(c3 - c2)) {
                                continue;
                            }
                            for (r4 = 1; r4 <= n; ++r4) {
                                for (c4 = 0; c4 < m; ++c4) {
                                    if (a[r4][c4] != 'N' || abs(r4 - r3) != abs(c4 - c3)) {
                                        continue;
                                    }
                                    cout << r1 << " " << c1 + 1 << '\n';
                                    cout << r2 << " " << c2 + 1 << '\n';
                                    cout << r3 << " " << c3 + 1 << '\n';
                                    cout << r4 << " " << c4 + 1 << '\n';
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    srch(n, m);
    return 0;
}
