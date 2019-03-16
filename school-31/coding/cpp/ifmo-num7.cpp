#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> a, b, c;

int main() {
	int n, k, key, cur, cnt;

	fin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for (int i = 0; i < n; ++i) {
		fin >> a[i];
	}

	fin >> k;
	for (int t = 0; t < k; ++t) {
		fin >> key;
		if (key == 1) {
			for (int i = 0; i < n; ++i) {
				b[i] += a[i];
			}
		}
		if (key == 2) {
			fin >> cur;
			for (int i = 0; i < n; ++i) {
				c[i] += cur;
			}
		}
		if (key == 3) {
			cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (c[i] < b[i]) {
					cnt += 1;
				}
			}
			fout << cnt << "\n";
		}
	}

	return 0;
}