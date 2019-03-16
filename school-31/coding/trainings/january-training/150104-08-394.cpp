#include <fstream>
#include <vector>
using namespace std;
ifstream cin("keyboard.in");
ofstream cout("keyboard.out");

vector<int> c;

int main() {
    int n, k, p;
    cin >> n;
    c.resize(n + 1);
    cin >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int j = 1; j <= k; ++j) {
        cin >> p;
        --c[p];
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] <= 0) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}
