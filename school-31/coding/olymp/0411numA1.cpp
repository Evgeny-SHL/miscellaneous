#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <deque>
#include <cmath>
#include <iostream>
using namespace std;

//ifstream cin("circle.in");
//ofstream cout("circle.out");

const double EPS = 1e-9;

int main() {
    int a, b, c;
    int x, y, r;
    double l;

    cin >> a >> b >> c >> x >> y >> r;

    cout << fixed;
    cout.precision(6);

    if (a == 0) {
        double t = r * r - (y + c / b) * (y + c / b);
        if (t < -EPS) {
            l = 0.0;
        } else {
            l = 2 * sqrt(r * r - (y + c / b) * (y + c / b));
        }
    } else {
        double a0 = b * b / (a * a) + 1;
        double b0 = b * x / a + b * c / (a * a) - y;
        double c0 = c * c / (a * a) + x* x + y * y - r * r + c * x / a;
        double d = b0 * b0 - a0 * c0;
    //    cout << d << '\n';
        if (d < -EPS) {
            l = 0.0;
        } else {
            double y1 = (-b0 - sqrt(d)) / a0;
            double y2 = (-b0 + sqrt(d)) / a0;
            double x1 = -c / a - b * y1 / a;
            double x2 = -c / a - b * y2 / a;
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
            l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }

    cout << fixed << setprecision(6) << l << '\n';

    return 0;
}
