#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cow;

ifstream cin ("baseball.in");
ofstream cout ("baseball.out");

int main() {

    int n;

    cin >> n;
    cow.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cow[i];
    }

    sort(cow.begin(), cow.end());

    int t = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (cow[j] - cow[i] <= cow[k] - cow[j] && cow[k] - cow[j] <= 2 * (cow[j] - cow[i])) {
                    ++t;
                }
            }
        }
    }

    cout << t << '\n';

    return 0;
}
