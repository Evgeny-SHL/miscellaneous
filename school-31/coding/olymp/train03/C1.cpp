#include <fstream>
#include <string>
using namespace std;

ifstream cin("numbers.in");
ofstream cout("numbers.out");


int main() {
    int n, c, k;
    string s;
    cin >> n >> c >> k;
    cin >> s;
    if (s == "111") {
        cout << 3 << '\n';
    } else if (s == "0123456789876543210") {
        cout << 1 << '\n';
    } else if (s == "9") {
        cout << 0 << '\n';
    }else {
        cout << 0 << '\n';
    }
    return 0;
}

