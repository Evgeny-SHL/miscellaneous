#include <iostream>
#include <vector>
using namespace std;

vector<int> x;
vector<int> y;

int main() {
    int n;
    cin >> n;
    x.resize(n, 0);
    y.resize(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    int ans = 0;
    for (int i = 0; i < n - 2; ++i)
        for (int j = i + 1; j < n - 1; ++j) {
            int t = 2;
            for (int k = j + 1; k < n; ++k) {
                if ((y[k] - y[i]) * (x[j] - x[i]) == (x[k] - x[i]) * (y[j] - y[i]))
                    ++t;
            }
            ans = max(ans, t);
        }

    cout << ans;

    return 0;
}
