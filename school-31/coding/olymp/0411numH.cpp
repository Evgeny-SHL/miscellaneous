#include <fstream>
#include <vector>
//#include <iostream>
#include <string>
#include <deque>
using namespace std;

ifstream cin("yoda.in");
ofstream cout("yoda.out");

deque<string> t;

int main() {
    string s;
    bool f = false;

    while (!cin.eof()) {
        cin >> s;
        if (s[s.length() - 1] == '.') {
            s.erase(s.length() - 1, 1);
            if (f) cout << " ";
            cout << s;
            while (!t.empty()) {
                cout << " " << t.back();
                t.pop_back();
            }
            cout <<  ".";
            f = true;
        } else {
            t.push_back(s);
        }
    }

    return 0;
}
