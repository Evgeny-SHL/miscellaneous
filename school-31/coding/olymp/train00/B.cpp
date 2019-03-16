#include <fstream>
using namespace std;

ifstream cin("conquest.in");
ofstream cout("conquest.out");

int main() {
    long long n, x, t;
    long long ans = 0;

    cin >> n;
    cin >> t;
    ans += t;
    for (int i = 1; i < n - 1; ++i) {
        cin >> x;
        t = min(t, x);
        ans += t;
    }

    if (n > 1) {
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
