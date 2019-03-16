#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("chess.in");
ofstream cout("chess.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

int main() {
    int n, m, i, j, c;
    cin >> n >> m >> i >> j >> c;
    if (m % 2 == 0 || n % 2 == 0) {
        cout << "equal";
    } else {
        if (0 == (i + j) % 2 && (m + n) % 2 == 0) {
            if (c == 1) {
                cout << "white";
            } else {
                cout << "black";
            }
        } else {
            if (c == 0) {
                cout << "white";
            } else {
                cout << "black";
            }
        }
    }
    cout << '\n';
    return 0;
}
