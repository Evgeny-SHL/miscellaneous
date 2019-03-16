#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > t;
vector< vector<long long> > d;
vector<int> used;

const long long INF = (long long)1e18;
long long ans;

void gen(int k, int mask) {
	for (int i = 0;)
}

int main() {
	int n;
	long long ans;

	cin >> x >> y;
	t.push_back(make_pair(x, y));
	cin >> n;
	t.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		t[i] = make_pair(x, y);
	}

	ans = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = (t[i].x - t[j].x) * (t[i].x - t[j].x) + (t[i].y - t[j].y) * (t[i].y - t[j].y);
		}
		ans += d[0][i];
	}

	gen(n, 0);

	return 0;
}
