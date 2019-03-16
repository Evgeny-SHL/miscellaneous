/*
ID: ugnthes1
PROG: skidesign
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

vector<int> h;

int main() {
	int n;

	fin >> n;
	h.resize(n);
	for (int i = 0; i < n; ++i) {
		fin >> h[i];
	}

	int best = 1e9 + 7;
	for (int low = 0; low <= 1000 - 17; ++low) {
		for (int high = low; high <= low + 17; ++high) {
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				if (h[i] < low) {
					sum += (low - h[i]) * (low - h[i]);
				} else if (h[i] > high) {
					sum += (h[i] - high) * (h[i] - high);
				}
			}
			best = min(best, sum);
		}
	}

	fout << best << "\n";

	return 0;
}