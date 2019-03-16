#include <fstream>
#include <iostream>
#include <string>
#include <set>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

set<char> v;

int main() {
	string s;
	int ans;

	getline(fin, s);

	v.insert('A');
	v.insert('E');
	v.insert('U');
	v.insert('I');
	v.insert('O');
	v.insert('Y');

	ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (v.find(s[i]) != v.end()) {
			++ans;
		}
	}

	fout << ans << '\n';

	return 0;
}
