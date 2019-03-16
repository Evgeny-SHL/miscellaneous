#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> dig;
set<long long> m;
set<long long> good, bad;

int main() {
	long long tests, n;

	fin >> tests;

	for (int t = 1; t <= tests; ++t) {
		fin >> n;
		long long s = n, sum;
		if (good.find(n) != good.end()) {
			s = 1;
			fout << "Case #" << t << ": " << n << " is a good number.\n";
			continue;
		} else if (bad.find(n) != bad.end()) {
			s = 2;
			fout << "Case #" << t << ": " << n << " is a bad number.\n";
			continue;
		}
		m.clear();
		do {
			m.insert(s);
			sum = 0;
			while (s > 0) {
				sum += (s % 10) * (s % 10);
				s /= 10;
			}
			s = sum;
			if (good.find(s) != good.end()) {
				s = 1;
				break;
			} else if (bad.find(s) != bad.end()) {
				s = 2;
				break;
			}
		} while (s != 1 && m.find(sum) == m.end());
		if (s == 1) {
			good.insert(m.begin(), m.end());
			fout << "Case #" << t << ": " << n << " is a good number.\n";
		} else {
			bad.insert(m.begin(), m.end());
			fout << "Case #" << t << ": " << n << " is a bad number.\n";
		}
	}

	return 0;
}


