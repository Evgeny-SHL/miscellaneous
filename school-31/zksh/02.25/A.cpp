#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> p;

int main() {
	int a, b, c, d;

	p.resize(4);
	cin >> p[0] >> p[1] >> p[2] >> p[3];
	sort(p.begin(), p.end());

	cout << p[0] * p[2] << "\n";

	return 0;
}