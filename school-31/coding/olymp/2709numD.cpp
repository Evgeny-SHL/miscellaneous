#include <iostream>+
#include <string>
using namespace std;

int main() {
    long long a = 0, b = 0, x;
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x % 2 == 0) ++a;
        else ++b;
    }

    cout << a * b;

    return 0;
}
