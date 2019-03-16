#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 2009000999LL;

ifstream in("input.txt");
ofstream out("output.txt");

struct edge {
	int finish, weight;
	edge(int fin = 0, int wei = 0) {
		finish = fin;
		weight = wei;
	}
};

struct h_t {
	long long ro;
	int finish;
	h_t(int b = 0, long long a = 0) {
		ro = a;
		finish = b;
	}
};

bool operator <(const h_t &a, const h_t &b) {
	return a.ro > b.ro;
}

vector<vector<edge> > g;

void dijkstra(int start, int n) {
	priority_queue<h_t> heap, copy;
	long long dist[n];
	bool used[n];
	for (int i = 0; i < n; ++i) {
		used[i] = false;
		dist[i] = INF;
		if (i != start) heap.push(h_t(i, INF));
	}
	heap.push(h_t(start, 0));
	/*copy = heap;
	while (!copy.empty()) {
		cout << copy.top().finish << " " << copy.top().ro << endl;
		copy.pop();
	}*/
	while (true) {
		while (!heap.empty() && used[heap.top().finish]) {
			heap.pop();
		}
		if (heap.empty()) break;
		int i_min = heap.top().finish;
		long long d_min = heap.top().ro;
		used[i_min] = true;
		dist[i_min] = d_min;
		heap.pop();
	//	cout << i_min << endl;
		for (unsigned int i = 0; i < g[i_min].size(); ++i) {
			heap.push(h_t(g[i_min][i].finish, d_min + g[i_min][i].weight));
		}
	}
	for (int i = 0; i < n; ++i)
		out << dist[i] << " ";
	out << '\n';
}

int main() {

	int num;
	int n, m;
	in >> num;
	for (int k = 0; k < num; ++k) {
		in >> n >> m;
		g.resize(n);
		int x, y, z;
		int start;
		for (int i = 0; i < m; ++i) {
			in >> x >> y >> z;
			g[x].push_back(edge(y, z));
			g[y].push_back(edge(x, z));
		}
		/*for (int i = 0; i < n; ++i) {
			cout << i << " : ";
			for (unsigned int j = 0; j < g[i].size(); ++j) {
				cout << g[i][j].finish << "/" << g[i][j].weight << " ";
			}
			cout << endl;
		}*/
		in >> start;
		dijkstra(start, n);
	}

	return 0;
}
