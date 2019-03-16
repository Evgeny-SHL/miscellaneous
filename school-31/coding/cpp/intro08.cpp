#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct state {
	long long num, dist;
	state(int a = 0, long long b = 0) {
		num = a;
		dist = b;
	}
};

string tostring(int x) {
	string s = "";
	while (x > 0) {
		s = char((x % 10) + '0') + s;
		x /= 10;
	}
	return s;
}

int p[100], r[100];
bool used[10000000];
queue<state> q;

long long bfs(int s, int k, int t) {
	if (s == t) return 0;
	q.push(state(s, 0));
	while (!q.empty()) {
		state ksi = q.front();
		q.pop();
		used[ksi.num] = true;
		string x = tostring(ksi.num), y, z;
	//	cout << ksi.num << " " << ksi.dist << endl;
		for (int i = 0; i < k; ++i) {
			y = tostring(p[i]);
			z = tostring(r[i]);
			for (int j = x.find(y, 0); j != string::npos; j = x.find(y, j)) {
				string x1 = x;
				x1.replace(j, 2, z);
				long long p = 0;
				for(int l = 0; l < x1.length(); ++l)
					p = 10 * p + (x1[l] - '0');
				if (p == t) return ksi.dist + 1;
				if (!used[p])  q.push(state(p, ksi.dist + 1));
				++j;
			}
		}
	}

	return -1;
}

int main() {
	int l, s, t, k;

	cin >> l >> s >> t >> k;
	for (int i = 0; i < k; ++i)
		cin >> p[i] >> r[i];

	cout << bfs(s, k, t);

	return 0;
}