#include <fstream>
#include <vector>
#include <string>
using namespace std;
ifstream cin("bw.txt");
ofstream cout("bw.txt");

vector<string> a, b;

int main() {
    int w, h;
    string op;
    string ksi;
    cin >> w >> h;
    a.resize(h);
    b.resize(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < h; ++i) {
        cin >> b[i];
    }
    cin >> op;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ksi = "";
            ksi += a[i][j];
            ksi += b[i][j];
            if (ksi == "00") {
                cout << op[0];
            } else if (ksi == "01") {
                cout << op[1];
            } else if (ksi == "10") {
                cout << op[2];
            } else {
                cout << op[3];
            }
        }
        cout << '\n';
    }
    return 0;
}
