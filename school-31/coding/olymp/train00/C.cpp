#include <fstream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;

ifstream cin("army.in");
ofstream cout("army.out");

int main() {
    int n, m, k, x, p;
    char c;
    cin >> n >> m;
    a.resize(n + 1);
    b.resize(n);

    cin >> a[0];
    p = 0;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        b[i - 1] = a[i] - a[i - 1];
        if (b[i - 1] < 0) {
            ++p;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> c;
        if (c == '?') {
            if (p == 0) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cin >> k >> x;
            a[k - 1] = x;
            bool f;
            if (k > 1) {
                f = b[k - 2] < 0;
                b[k - 2] = a[k - 1] - a[k - 2];
                if (f && b[k - 2] >= 0) {
                    --p;
                } else if (!f && b[k - 2] < 0) {
                    ++p;
                }
            }
            if (k < n) {
                f = b[k - 1] < 0;
                b[k - 1] = a[k] - a[k - 1];
                if (f && b[k - 1] >= 0) {
                    --p;
                } else if (!f && b[k - 1] < 0) {
                    ++p;
                }
            }
        }
    }

    return 0;
}
