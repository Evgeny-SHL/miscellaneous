#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream cin("elephants.in");
ofstream cout("elephants.out");

vector<string> a;
vector< pair<int, int> > ans;

bool srch(char c, int n, int m) {
    for (in )
}

int main() {
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    ans.resize(4);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bool f = false;
    for (int i = 1; (i <= n) && !f; ++i) {
        if(a[i][j] == 'S') {
            f = srch('S', n, m);
        }
    }
    return 0;
}
