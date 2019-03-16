#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:16777216")

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< pair<int, string> > teams;

int main() {
	freopen("football.in", "r", stdin);
	freopen("football.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, points;
	string vasya, petya, name;
	cin >> n;
	cin >> vasya;
	cin >> petya;
	for (int i = 0; i < n; ++i) {
		cin >> name >> points;
		teams.push_back(make_pair(-points, name));
	}
	for (int i = 0; i < n; ++i) {
		if (teams[i].second == vasya) {
			teams[i].first -= 3;
		}
	}
	sort(teams.begin(), teams.end());
	for (int i = 0; i < n; ++i) {
		if (teams[i].second == vasya) {
			cout << (i + 1) << " ";
			teams[i].first += 2;
		} else if (teams[i].second == petya) {
			teams[i].first -= 1;
		}
	}
	sort(teams.begin(), teams.end());
	for (int i = 0; i < n; ++i) {
		if (teams[i].second == vasya) {
			cout << (i + 1) << " ";
			teams[i].first += 1;
		} else if (teams[i].second == petya) {
			teams[i].first -= 2;
		}
	}
	sort(teams.begin(), teams.end());
	for (int i = 0; i < n; ++i) {
		if (teams[i].second == vasya) {
			cout << (i + 1) << "\n";
		}
	}

	return 0;
}
