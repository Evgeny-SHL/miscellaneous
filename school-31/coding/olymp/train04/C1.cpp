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

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

set<char> pt;
string text;

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
	char c;
	text = "";
	while (!fin.eof()) {
		fin >> c;
		text += c;
	}
	cout << text;
	return 0;
}
