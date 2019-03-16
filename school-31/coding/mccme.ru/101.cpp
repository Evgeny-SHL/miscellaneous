#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> p;

int main() {
	string t;
	int k, n;

	getline(fin, t);

	n = t.length();
	k = 0;
	p.resize(n);
	p[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && t[i] != t[j]) {
			j = p[j - 1];
		}
		if (t[i] == t[j]) {
			++j;
		}
		p[i] = j;
		if (j > k) {
			k = j;
		}
	}

	fout << n - p[n - 1] << "\n";

	return 0;
}