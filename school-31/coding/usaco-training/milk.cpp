/*
ID: ugnthes1
PROG: milk
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

struct farmer {
	int p, a;
	farmer (int x = 0, int y = 0) {
		p = x;
		a = y;
	}
};

bool comp(farmer a, farmer b) {
	return a.p < b.p;
}

vector<farmer> men(5000);

int main() {
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");

	int n, m;

	fin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		fin >> x >> y;
		men[i] = farmer(x, y);
	}

	sort(men.begin(), men.end(), comp);

	int i = 0;
	long long costs = 0;
	while (n > 0) {
		int k = min(n, men[i].a);
		n -= k;
		costs += k * men[i].p;
		++i;
	}

	fout << costs << endl;

	return 0;
}