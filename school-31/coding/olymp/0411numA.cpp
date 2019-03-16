#include <fstream>
#include <vector>
//#include <iostream>
using namespace std;

ifstream cin("race.in");
ofstream cout("race.out");

vector<int> a;
vector<int> b;

int main() {
    int n;

    cin >> n;

    a.resize(n + 1, 0);
    b.resize(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = min(b[i + 1], a[i + 1]);
    }
    b[n - 1] = n + 1;

 //   for (int i = 0; i < n; ++i) {
 //       cout << b[i] << " ";
 //   }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (i  + 1 < b[i]) {
            ++k;
        //    cout << i + 1 << " ";
        }
    }

    cout << k << '\n';
    for (int i = 0; i < n; ++i) {
        if (i  + 1 < b[i]) {
         //   ++k;
           cout << i + 1 << " ";
        }
    }

    cout << '\n';

    return 0;
}
