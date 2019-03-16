/*
ID: ugnthes1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gap(200);
vector<int> stall(200);

int main() {
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");

	int m, s, c;

	fin >> m >> s >> c;

	for (int i = 0; i < c; ++i)
		fin >> stall[i];

	sort(stall.begin(), stall.begin() + c);

	for (int i = 1; i < c; ++i) {
		gap[i - 1] = stall[i] - stall[i - 1] - 1;
	}

	sort(gap.begin(), gap.begin() + c - 1);

	int ans = stall[c - 1] - stall[0] + 1;
	for (int i = c - 2; i >= max(0, c - m); --i)
		ans -= gap[i];

	fout << ans << endl;

	return 0;
}