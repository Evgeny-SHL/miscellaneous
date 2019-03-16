#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> pr;

struct way {
    long long num;
    string w;
    way(long long a = 0) {
        num = a;
    }
};

queue<way> q;

int main() {
    long long a, b;
    bool one = false;
    cin >> a >> b;

    way ksi = way(a), ksi1;
    ksi.w = "";
    q.push(way(ksi));
    while(!q.empty() && q.front().num != b) {
        ksi = q.front();
        a = ksi.num;

        if (a * a <= b && a != 1) {
            ksi1 = way(a * a);
            ksi1.w = ksi.w + "*";
            q.push(ksi1);
        }

        if (2 * a <= b) {
            ksi1 = way(2 * a);
            ksi1.w = ksi.w + "+";
            q.push(ksi1);
        }

        if (!one) {
            ksi1 = way(1);
            ksi1.w = ksi.w + "/";
            q.push(ksi1);
            one = true;
        }

        q.pop();
    }
    if (q.empty()) cout << ":-(";
    else {
        way ans = q.front();
        cout << ans.w << '\n';
    }

    return 0;
}
