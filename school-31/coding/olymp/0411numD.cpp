#include <fstream>
#include <string>
using namespace std;

ifstream cin("squad.in");
ofstream cout("squad.out");

int main() {
    string a;
    string b;

    cin >> a >> b;

    for (int i = 0; i < a.length(); ++i) {
        cout << max(a[i], b[i]);
    }

    return 0;
}
