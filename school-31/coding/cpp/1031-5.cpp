#include <iostream>
#include <map>
#include <string>
using namespace std;

map<map<string, int>, int> g;
map<string, int> pupil;
map<string, bool> colored;

void dfs(string s) {
	colored[s] = true;
	for (map<string, int>::iterator it = g[s].begin(); it != g[s].end(); ++it) {
		if (!colored[it -> first]) {
			it -> second
		}
	}
}

int main() {
	int n, age;
	string pred, succ;
	colored["Ted"] = false;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pred >> succ >> age;
		pupil[succ] = age;
		g[pupil] = 100;
		colored[succ] = false;
	}

	dfs("Ted");

	return 0;
}