#include <iostream>
using namespace std;

int main() {
    for (int a = 'A'; a <= 'Z'; ++a) {
        for (int b = 'a'; b <= 'z'; ++b) {
            for (int c = 'A'; c <= 'Z'; ++c) {
                if (a * a + b * b == c * c) {
                    cout << char(a) << char(b) << " " << char(c) << endl;
                }
            }
        }
    }
}