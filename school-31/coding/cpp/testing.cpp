#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> a;

int main() {
#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	a.resize(20);
	for (int i = 0; i < 20; ++i) {
		a[i] = i * i;
	}
	for (int y: a) {
		cout << y << "\n";
	}
	return 0;
}