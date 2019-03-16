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

set<string> first, second;
vector<string> common;

string to_lower(string s) {
	int n = (int)s.length();
	for (int i = 0; i < n; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = (char)(s[i] + 'a' - 'A');
		}
    }
    return s;
}

set<string> div_words(string s) {
	set<string> w;
	int n = (int)s.length();
	for (int i = 0; i < n; ++i) {
		string word = "";
		for (; i < n && s[i] >= 'a' && s[i] <= 'z'; ++i) {
			word += s[i];
		}
		if (word != "") {
			w.insert(word);
		}
	}
	return w;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

    string s1;
    string s2;
	getline(cin, s1);
	getline(cin, s2);
    s1 = to_lower(s1);
    s2 = to_lower(s2);
	first = div_words(s1);
	second = div_words(s2);
	for (auto word: first) {
		if (second.find(word) != second.end()) {
			common.push_back(word);
		}
	}
	int k = common.size();
	sort(common.begin(), common.end());
	for (int i = 0; i < k - 1; ++i) {
		cout << common[i] << " ";
	}
	if (k > 0) {
		cout << common[k - 1];
	}
	cout << "\n";

	return 0;
}