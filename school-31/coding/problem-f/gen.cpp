#include <fstream>
#include <set>
#include <random>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

ofstream fout("input.txt");

int P[30];
int Max = 10;
set< pair<int, int> > edges;

int main() {
	freopen("input.txt", "r", stdin);
	unsigned long long t = 1;
	for(int i = 0; i < 100; i++){
		unsigned long long e;
		cin >> e;
		t *= e + 3;
		t %= 123125125;
		t += 123125125;
	}

	srand((unsigned long long)((time(NULL) + 3) * (clock() + 3) * t));
	int n = 2 + rand() % Max;
	int e = n * (n - 1) / 2;
	int m = 1 + rand() % e;
	while (edges.size() < m) {
		int u = 1 + rand() % n;
		int v = 1 + rand() % n;
		if (u > v) {
			swap(u, v);
		}
		if (u != v) {
			edges.insert(make_pair(u, v));
		}
	}
	fout << n << " " << m << "\n";
	for (auto it = edges.begin(); it != edges.end(); ++it) {
		fout << it->first << " " << it->second << "\n";
	}
	return 0;
}