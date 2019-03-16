#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> p;

int main() {
	string P, T;
	int n, m;

	getline(fin, T);
	getline(fin, P);

	m = P.length();
	T = P + "#" + T;
	n = T.length();

	p.resize(n);
	p[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && T[i] != T[j]) {
			j = p[j - 1];
		}
		if (T[i] == T[j]) {
			++j;
		}
		p[i] = j;
		if (j == m) {
			fout << i - 2 * m << " ";
		}
	}
	fout << "\n";

	return 0;
}