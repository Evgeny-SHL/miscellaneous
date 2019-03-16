#include <iostream>
using namespace std;

int main() {
    int n, x, m, s;

    cin >> n;
    m = 0;
    s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
        m = max(m, x);
    }

    cout << s - m;

    return 0;
}
