/*
ID: ugnthes1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool milk[1000000];

int main() {
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

	int n, k = 0;

	fin >> n;
	int minstart = 1000000;
	int maxfinish = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		fin >> a >> b;
		minstart = min(minstart, a);
		maxfinish = max(maxfinish, b);
		for (int j = a; j < b; ++j)
			milk[j] = true;
	}

	int x = 0, y = 0, z1 = 0, z2 = 0;
	for (int i = minstart; i <= maxfinish; ++i) {
		if (milk[i]) {
			++z1;
			y = max(z2, y);
			z2 = 0;
		}
		else {
			++z2;
			x = max(z1, x);
			z1 = 0;
		}
	}

	fout << x << " " << y << endl;

	return 0;
}