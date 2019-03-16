#include <fstream>
#include <string>
using namespace std;

ifstream cin("tesseract.in");
ofstream cout("tesseract.out");

bool pal(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    string s1, s2;
    bool f;

    getline(cin, s);

    long long k = 0;
    int n = s.length();
    for (int m = 1; m <= n; ++m) {
        for (int i = 0; i <= n - m; ++i) {
            s1 = s.substr(i, m);
            if (pal(s1)) {
                f = false;
                for (int q = 1; (q <= n) && !f; ++q) {
                    for (int j = 0; (j <= n - q) && !f; ++j) {
                        if ((i >= j) && (i + m - 1 <= j + q - 1)) {
                            s2 = s.substr(j, q);
                            if ((i != j || m != q) && pal(s2)) {
                                f = true;
                            }
                        }
                    }
                }
                if (f) {
                    ++k;
                //    cout << s1 << '\n';
                 //   cout << s2 << '\n';
                }
            }
        }
    }

    cout << k << '\n';

    return 0;
}
