#include <fstream>
#include <vector>
using namespace std;

struct cow {
    int g, d;
    bool used;
    cow (int a = 0, int b = 0) {
        g = a;
        d = b;
        used = false;
    }
};

vector<cow> milk;

ifstream cin ("msched.in");
ofstream cout ("msched.out");

int main() {

    int n, a, b;
    cin >> n;
    milk.resize(n);
    int max_t = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        max_t = max(max_t, b);
        milk[i] = cow(a, b);
    }

    int sum = 0;
    for (int t = 1; t <= max_t; ++t) {
        int m = -1;
        for (int i = 0; i < n; ++i) {
            if (!milk[i].used && milk[i].d >= t && milk[i].g > milk[m].g) {
                m = i;
            }
        }
        if (m != -1) {
            milk[m].used = true;
            sum += milk[m].g;
        }
   //     cout << milk[m].g << " ";
    }
 //   cout << '\n';

    cout << sum << '\n';

    return 0;
}

//map<int, int>::iterator i = milk.begin(); i != milk.end(); i++
//i->first
//i->second
