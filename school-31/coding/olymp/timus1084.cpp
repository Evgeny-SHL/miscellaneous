#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14159265359;

int main() {
    int l, r;
    double ans;

    cin >> l >> r;

    if (l >= 2 * r) {
        ans = pi * r * r;
    } else if (l < sqrt(2) * r) {
        ans = l * l;
    } else {
        double phi = 2 * acos(l / (2.0 * r));
    //    cout << phi << '\n';
        double s_segm = 0.5 * r * r * (phi - sin(phi));
        ans = pi * r * r - 4 * s_segm;
    }

    cout.precision(3);
    cout << fixed;
    cout << ans;

    return 0;
}
