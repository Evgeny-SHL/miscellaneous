#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> b;

int main() {
    int n, ans = 0, k = 1;
    string s;
    b['A'] = 1;
    b['P'] = 1;
    b['O'] = 1;
    b['R'] = 1;
    b['B'] = 2;
    b['M'] = 2;
    b['S'] = 2;
    b['D'] = 3;
    b['G'] = 3;
    b['J'] = 3;
    b['K'] = 3;
    b['T'] = 3;
    b['W'] = 3;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ans += abs(b[s[0]] - k);
        k = b[s[0]];
    }

    cout << ans;

    return 0;
}
