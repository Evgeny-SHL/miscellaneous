#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int MAX = (int)1e5 + 10;

map<long long, int> ind;
vector< vector<long long> > p;
vector<long long> a, b, c;

int main() {
	int n, t;

	fin >> n >> t;

	c.resize(n + 1);
	p.resize(n + 1, vector<long long>(MAX, 0));
	for (int i = 1; i <= n; ++i) {
		fin >> c[i];
		if (ind.find(c[i]) == ind.end()) {
			a.push_back(i);
			ind[c[i]] = (int)a.size() - 1;
			p[ind[c[i]]][i] = 1;
		} else {
			++p[ind[c[i]]][i];
		}

	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)a.size(); ++j) {
			p[j][i] += p[j][i - 1];
		}
	}

	/*for (int i = 0; i <= n; ++i) {
		cout << ind[c[i]] << "\n";
		for (int j = 0; j < (int)a.size(); ++j) {
			cout << p[j][i] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 1; i <= t; ++i) {
		cin >> l >> r;

	}

	return 0;
}
