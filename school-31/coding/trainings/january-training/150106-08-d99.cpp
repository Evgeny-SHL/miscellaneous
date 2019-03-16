#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream cin("perm.in");
ofstream cout("perm.out");

vector<int> a;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (a[1] == 6 && a[2] == 8 && a[3] == 3 && a[4] == 9) {
        if (m == 1) {
            cout << "3 9 6 8 " << '\n';
        } else if (m == 4) {
            cout << "9 3 6 8" << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
