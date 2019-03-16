#include <iostream>
#include <string>
using namespace std;

bool pal(string s) {
    int n = s.length();
    for (int i = 0; i <= n / 2; ++i)
        if (s[i] != s[n - i - 1]) return false;
    return true;
}

int main() {

    string s1;
    cin >> s1;

    int k = 1;
    int n = s1.length();
    if (n == 0) cout << s1 << s1;
    else {
        while (!pal(s1.substr(k, n - k))) {
            ++k;
        }

        cout << s1;
        for (int i = k - 1; i >= 0; --i)
            cout << s1[i];
    }

   return 0;
}
