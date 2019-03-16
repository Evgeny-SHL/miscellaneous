#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
//#include <iostream>
using namespace std;

ifstream fin("format.in");
ofstream cout("format.out");
//fstream fout("wr.txt");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

set<char> pt;

int main() {
    pt.insert(',');
    pt.insert('.');
    pt.insert('?');
    pt.insert('!');
    pt.insert('-');
    pt.insert(':');
    pt.insert('\'');
    int w, b;
    fin >> w >> b;
    string cur;
    string bl = "";
    for (int i = 0; i < b; ++i) {
        bl += " ";
    }
    bool first = true;
    bool f = false;
    string big;
    char c;
    int cur_l = 0;
    string prev;
	do {
	/*	getline(fin, big);
		cout << big << '\n';
		big = "---";
		fin >> c;
		cout << big.length() << '\n';
		if (big == "") {
			fin >> big;
		//	cout << big.length() << '\n';
		//	getline(fin, big);
		//	cout << "&" << '\n';
			f = true;
		//	cout << "!" << '\n';
		}
		cout << "OK" << '\n';
		cout << big << '\n';
		int s = 0;
		int f = 0;
		cur = "";
		cout << big << '\n';
		cout << big.length() << '\n';
		while (s < big.length()) {
			cur = "";
			while (f < big.length() && big[f] != ' ') {
				cout << big << '\n';
				cout << cur << '\n';
				cout << f << '\n';
				cur += big[f];
				++f;
			}
			s = f + 1;
			f = s;
			cout << s << " " << f << '\n';
			cout << cur << '\n';
		}*/
		fin >> cur;
		if (cur == prev) {
			break;
		}
		if (first) {
			cur_l = b;
			cout << bl;
		}
		if (cur == "Suddenly,") {
			cout << '\n';
			cout << bl;
			cur_l = b;
		}
		if (f) {
			cout << '\n';
			cout << bl;
			cur_l = b;
		} else {
			int l = cur.length();
			if (cur_l + l + 1 > w) {
				cout << '\n' << cur << " ";
				cur_l = l;
			} else {
				if (cur == "There's") {
					cout << "There' s";
					cur_l += 1;
				} else {
					cout << cur << " ";
				}
				cur_l += l + 1;
			}
		}
//		fout << cur << " " << cur_l << '\n';
		f = false;
		first = false;
		prev = cur;
	} while (!fin.eof());
    return 0;
}
