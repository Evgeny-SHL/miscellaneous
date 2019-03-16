#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< vector<bool> > g;

int main() {
	long long h, w, k, l, s, l1;
	long long rh, ch, rt, ct;
	char c;
	string prg;
	cin >> h >> w >> k >> c;
	getline(cin, prg);
	prg = c + prg;
	g.resize(h + 2);
	for (long long i = 0; i <= h + 1; ++i) {
		g[i].resize(w + 2, false);
	}
//	cout << h << w << k;
//	cout << prg;
//	cout << '\n';
	rh = rt = 1;
	ch = ct = 1;
//	cout << "Head" << '\n';
	l = 0;
	s = 0;
	do {
		g[rh][ch] = true;
		++l;
//		cout << l << " " << rh << " " << ch << " " << prg[s] << '\n';
		if (prg[s] == 'U') {
			if (rh == 1) {
				rh = h;
			} else {
				--rh;
			}
		} else if (prg[s] == 'L') {
			if (ch == 1) {
				ch = w;
			} else {
				--ch;
			}
		} else if (prg[s] == 'R') {
			if (ch == w) {
				ch = 1;
			} else {
				++ch;
			}
		} else if (prg[s] == 'D') {
			if (rh == h) {
				rh = 1;
			} else {
				++rh;
			}
		}
		++s;
		if (s == k) {
			s = 0;
		}
	//	cout << l << ": " << rh << " " << ch << '\n';
	} while (!g[rh][ch] || (rh == rt && ch == ct));
//	cout << "Tail" << '\n';
	l1 = 0;
	s = 0;
	do {
		++l1;
//		cout << l1 << " " << rt << " " << ct << " " << prg[s] << '\n';
		if (prg[s] == 'U') {
			if (rt == 1) {
				rt = h;
			} else {
				--rt;
			}
		} else if (prg[s] == 'L') {
			if (ct == 1) {
				ct = w;
			} else {
				--ct;
			}
		} else if (prg[s] == 'R') {
			if (ct == w) {
				ct = 1;
			} else {
				++ct;
			}
		} else if (prg[s] == 'D') {
			if (rt == h) {
				rt = 1;
			} else {
				++rt;
			}
		}
		++s;
		if (s == k) {
			s = 0;
		}
		//	cout << l << ": " << rh << " " << ch << '\n';
	} while (rt != rh || ct != ch);
//	cout << l << '\n';
//	cout << l1 << '\n';
	cout << l - l1 << '\n';
	return 0;
}