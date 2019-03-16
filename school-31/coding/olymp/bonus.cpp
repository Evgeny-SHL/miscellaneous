#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dig[32];

    int k = 0;
    while (n > 0) {
        dig[k] = n % 2;
        ++k;
        n /= 2;
    }

    for (int i = 0; i < k; ++i)
        cout << dig[i];
    cout << '\n';

    long long sum = 1;
    bool f = 0;
    for (int i = 1; i < k; ++i) {
        if (dig[i] == 0 || dig[i - 1] > 0) {
            f = false;
            continue;
        }
        if (f) sum += 1;
        else sum *= 2;
        dig[i] = 0;
        dig[i - 1] = 2;
        f = true;
    }

    cout << sum;

    return 0;
}
