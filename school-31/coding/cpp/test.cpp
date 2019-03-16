#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a;
    int b = 3;
    int& c = b;
    c++;
    cout << b << "\n";
/*    size_t* len = &a.size();
    for (int i = 0; i < 10; ++i) {
        cout << a.size() << " " << len << " ";
        a.push_back(i);
        cout << a[len - 1] << "\n";
    }*/
    return 0;
}