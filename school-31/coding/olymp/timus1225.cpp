#include <iostream>
using namespace std;

int main() {

    long long f[50];
    f[0] = 1;
    f[1] = 1;

    int n;
    cin >> n;

    for (int i = 2; i < n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }

    cout << 2 * f[n - 1];

    return 0;
}
