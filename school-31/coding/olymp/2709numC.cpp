#include <iostream>+
#include <string>
using namespace std;

int main() {
    int a[26];
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < 26; ++i)
        a[i] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a[int(s[0]) - int('a')]++;
    }
    bool f = false;
    for (int i = 0; i < 26; ++i) {
        if (a[i] >= 5) {
            f = true;
            cout << char(i + 'a');
        }
    }
    if (!f) cout << "PREDAJA";

    return 0;
}
