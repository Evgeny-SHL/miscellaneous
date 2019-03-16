#include <fstream>
#include <string>
using namespace std;

ifstream cin("triangle.in");
ofstream cout("triangle.out");

const double EPS = 1e-6;

int main() {
    int n;
    string key;
    double f_min = 30.0, f_max = 4000.0, f, f_cur, f_prev;
    cin >> n;
    cin >> f_prev;
    for (int i = 2; i <= n; ++i) {
        cin >> f_cur >> key;
        if (key == "closer") {
            bool lssr = (f_cur - f_prev > EPS);
            if (lssr) {
                f_min = max(f_min, (f_cur + f_prev) / 2.0);
            } else {
                f_max = min(f_max, (f_cur + f_prev) / 2.0);
            }
        } else {
            bool grtr = (f_cur - f_prev > EPS);
            if (grtr) {
                f_max = min(f_max, (f_cur + f_prev) / 2.0);
            } else {
                f_min = max(f_min, (f_cur + f_prev) / 2.0);
            }
        }
        f_prev = f_cur;
     //   cout << f_min << " " << f_max << '\n';
    }
    cout << fixed;
    cout.precision(6);
    cout << f_min << " " << f_max << '\n';
    return 0;
}
