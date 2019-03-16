#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin("addition.in");
ofstream cout("addition.out");

vector<long long> arr;
set<string> sums;

string _sum(string a, string b) {
    string ans = "";
    int d1, d2;
    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (a.length() > b.length()) {
        b = "0" + b;
    }
 //   cout << a << " " << b << '\n';
    int n = (int)a.length();
    for (int i = n - 1; i >= 0; --i) {
        d1 = (int)(a[i] - '0');
        d2 = (int)(b[i] - '0');
        ans = char((d1 + d2) % 10 + '0') + ans;
        if (d1 + d2 > 9) {
            ans = char((d1 + d2) / 10 + '0') + ans;
        }
    }
    return ans;
}

long long to_num(string s) {
    int n = (int)s.length();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = 10 * ans + (int)(s[i] - '0');
    }
    return ans;
}

int main() {
    int k = 0;
    string a, b, c, s;
    cin >> a >> b >> c;
    arr.resize(6);
    s = _sum(a, _sum(b, c));
    sums.insert(s);
    arr[k++] = to_num(s);
    s = _sum(a, _sum(c, b));
 //   cout << s << '\n';
    if (sums.find(s) == sums.end()) {
        sums.insert(s);
        arr[k++] = to_num(s);
    }
    s = _sum(b, _sum(a, c));
 //   cout << s << '\n';
    if (sums.find(s) == sums.end()) {
        sums.insert(s);
        arr[k++] = to_num(s);
    }
    s = _sum(b, _sum(c, a));
 //   cout << s << '\n';
    if (sums.find(s) == sums.end()) {
        sums.insert(s);
        arr[k++] = to_num(s);
    }
    s = _sum(c, _sum(a, b));
//    cout << s << '\n';
    if (sums.find(s) == sums.end()) {
        sums.insert(s);
        arr[k++] = to_num(s);
    }
    s = _sum(c, _sum(b, a));
//    cout << s << '\n';
    if (sums.find(s) == sums.end()) {
        sums.insert(s);
        arr[k++] = to_num(s);
    }
    if (k > 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; ++i) {
        cout << arr[i] << '\n';
    }
    return 0;
}
