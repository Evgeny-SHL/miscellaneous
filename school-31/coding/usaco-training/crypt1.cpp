/*
ID: ugnthes1
PROG: crypt1
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

set<int> dig;

bool InSet(int x) {
	while (x > 0) {
		int d = x % 10;
		if (dig.find(d) == dig.end()) return false;
		x /= 10;
	}
	return true;
}

int main() {
    ifstream fin ("crypt1.in");
    ofstream fout ("crypt1.out");

	int n, d;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> d;
		dig.insert(d);
	}

	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		if (dig.find(i) == dig.end()) continue;
		for (int j = 1; j <= 9; ++j) {
			if (dig.find(j) == dig.end()) continue;
			for (int k = 1; k <= 9; ++k) {
				if (dig.find(k) == dig.end()) continue;
				for (int i1 = 1; i1 <= 9; ++i1) {
					if (dig.find(i1) == dig.end()) continue;
					for (int j1 = 1; j1 <= 9; ++j1) {
						if (dig.find(j1) == dig.end()) continue;
						int a = 100 * i + 10 * j + k;
						int b = 10 * i1 + j1;
						int p1 = a * i1, p2 = a * j1, p = a * b;
						if (InSet(p1) && p1 >= 100 && p1 <= 999 &&
						InSet(p2) && p2 >= 100 && p2 <= 999 &&
						InSet(p) && p >= 1000 && p <= 9999) {
							++ans;
						}
					}
				}
			}
		}
	}

	fout << ans << endl;

	return 0;
}