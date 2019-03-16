#include <iostream>
#include <vector>
using namespace std;

struct edge {
	long long u, d;
	edge(long long a = 0, long long b = 0) {
		u = a;
		d = b;
	}
};

vector< vector<edge> > g;
vector<long long> s;
//vector<long long> p;
vector<long long> cnt;
vector<long long> used;

void dfs(long long r) {
	used[r] = 2;
	s[r] = 0;
//	p[r] = 0;
	cnt[r] = 1;
	for (long long i = 0; i < g[r].size(); ++i) {
		long long u = g[r][i].u;
		if (used[u] == 0) {
			dfs(u);
			cnt[r] += cnt[u];
		//	p[r] += p[u] + g[r][i].d;
			used[u] = 1;
		}
	}
	for (long long i = 0; i < g[r].size(); ++i) {
		long long u = g[r][i].u;
		if (used[u] == 1) {
			s[r] += s[u] * (cnt[r] - cnt[u]) + g[r][i].d * cnt[u] * (cnt[r] - cnt[u]);
			used[u] == 2;
		}
	}
}

int main() {
	long long t, n, a, b, d, k;

	cout << fixed;
	cout.precision(3);

	cin >> t;
	for (long long i = 1; i <= t; ++i) {
		cin >> n;
		k = n * (n - 1) / 2;
	//	p.resize(n, 0);
		g.resize(n);
		s.resize(n, 0);
		cnt.resize(n, 0);
		used.resize(n, 0);
		for (long long j = 1; j < n; ++j) {
			cin >> a >> b >> d;
			g[a].push_back(edge(b, d));
			g[b].push_back(edge(a, d));
		}
		dfs(0);
		for (int j = 0; j < n; ++j) {
			cout << s[j] << " " << " " << cnt[j] << '\n';
		}
		cout << 1.0 * s[0] / k << '\n';
		g.clear();
		s.clear();
		cnt.clear();
		used.clear();
	//	p.clear();
	}

	return 0;
}