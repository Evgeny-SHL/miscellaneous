#include <fstream>
#include <string>
using namespace std;
ifstream cin("race.in");
ofstream cout("race.out");

int main() {
    int n, m, time, c, s;
    cin >> n >> m;
    string winner = "", name;
    time = 1000000;
    for (int i = 1; i <= n; ++i) {
        cin >> name;
        s = 0;
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            s += c;
        }
        if (s < time) {
            winner = name;
            time = s;
        }
    }
    cout << winner << '\n';
    return 0;
}
