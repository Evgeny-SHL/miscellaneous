#include <fstream>
#include <vector>
#include <string>
using namespace std;
ifstream cin("negative.in");
ofstream cout("negative.out");

vector<string> a, b;

int main() {
    string blank;
    int w, h, ans = 0;
    cin >> h >> w;
    a.resize(h);
    b.resize(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
 //   cin >> blank;
    for (int i = 0; i < h; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == b[i][j]) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
