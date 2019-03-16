#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
vector<int> st;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second - a.first < b.second - b.first)
		return true;
	if (a.second - a.first ==  b.second - b.first && a.first < b.first)
		return true;
	return false;
}

int main() {
	int n, k, t;

	cin >> n >> k;
	st.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> st[i];

	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			v.push_back(make_pair(min(st[i], st[j]), max(st[i], st[j])));

	sort(v.begin(), v.end(), comp);

	cout << v[k - 1].first << " " << v[k - 1].second << '\n';

	return 0;
}