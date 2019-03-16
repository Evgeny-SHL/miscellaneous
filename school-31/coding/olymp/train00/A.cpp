#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> face;

ifstream cin("nose.in");
ofstream cout("nose.out");

int main() {
    int n, m;

    cin >> n >> m;
    face.resize(n);

    getline(cin, face[0]);
    for (int i = 0; i < n; ++i) {
        getline(cin, face[i]);
    //    cout << face[i] << '\n';
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (face[i][j] == face[i][j - 1] && face[i][j] == '.') {
                ++ans;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (face[i][j] == face[i - 1][j] && face[i][j] == '.') {
                ++ans;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
