#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream cin("perm.in");
ofstream cout("perm.out");

vector<int> a;
/*vector<bool> used;
vector<int> cur;
vector< vector<int> > before;
vector<string> ans;
*/
bool gcd(int a, int b, int k) {
    int v;
    while (b != 0) {
        v = b;
        b = a % b;
        a = v;
    }
    return (a >= k);
}

/*void cmp_srch(int ind, int n, int m, int k, vector<int> cur, vector<bool> used) {
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && gcd(cur[ind], a[i], k)) {
            cur.push_back(a[i]);
        }
    }
}*/

/*void get_ans(int n, int m, int k) {
    for (int i = 1; i <= n; ++i) {
        cur.push_back(a[i]);
        used[i] = true;
        cmp_srch(0, n, m, k, cur, used);
        cur.pop_back();
        used[i] = false;
    }
}*/

int main() {
    int n, m, k;
    int t = 0;
    bool f = true;
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    do {
        f = true;
        for (int i = 0; i < n - 1; ++i) {
            if (!gcd(a[i], a[i + 1], k)) {
                f = false;
            }
        }
        if (f) {
            --m;
        }
        if (m == 0) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << '\n';
        }
    } while (m > 0 && next_permutation(a.begin(), a.end()));
    if (m > 0) {
        cout << -1 << '\n';
    }
    return 0;
}
