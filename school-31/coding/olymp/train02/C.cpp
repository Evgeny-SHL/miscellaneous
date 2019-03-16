#include <fstream>
#include <vector>
using namespace std;

ifstream cin("partition.in");
ofstream cout("partition.out");

vector<int> a;

void prt(int n) {
    int l;
    if (n == 0) {
        for (int i = 0; i < (int)a.size() - 1; ++i) {
            cout << a[i] << "+";
        }
        cout << a[a.size() - 1] << '\n';
    }
    l = 1;
    if (a.size() > 0) {
        l = a[a.size() - 1];
    }
    for (int i = l; i <= n; ++i) {
        a.push_back(i);
        prt(n - i);
        a.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    prt(n);
    return 0;
}

