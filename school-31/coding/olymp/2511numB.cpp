#include <iostream>
#include <vector>
using namespace std;

vector<int> milk;

int main() {

    int n, a, b;
    milk.resize(10001);

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        milk[b] = max(a, milk[b]);
    }

    int sum = 0;
    for (int i = 1; i <= 10000; ++i) {
        sum += milk[i];
    }

    cout << sum << '\n';

    return 0;
}

//map<int, int>::iterator i = milk.begin(); i != milk.end(); i++
//i->first
//i->second
