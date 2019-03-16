#include <fstream>
//#include <iostream>
#include <vector>
using namespace std;

const long long INF = 10000000000LL;

ifstream in("input.txt");
ofstream out("output.txt");

struct edge {
	int finish, weight;
	edge(int fin = 0, int wei = 0) {
		finish = fin;
		weight = wei;
	}
};

vector<vector<edge> > g;

void dijkstra(int start, int n) {
	long long dist[n];
	bool used[n];
	for (int i = 0; i < n; ++i) {
		used[i] = false;
		dist[i] = INF;
	}
	dist[start] = 0;
	while (true) {
		int i_min = -1;
		long long d_min = INF;
		for (int i = 0; i < n; ++i) {
		//	cout << i << " " << dist[i] << " " << d_min << " " << used[i] << endl;
			if ((dist[i] < d_min) && (!used[i])) {
				d_min = dist[i];
				i_min = i;
			}
		}
		used[i_min] = true;
		if (i_min == -1) break;
		for (unsigned int i = 0; i < g[i_min].size(); ++i) {
			if (d_min + g[i_min][i].weight < dist[g[i_min][i].finish]) {
				dist[g[i_min][i].finish] = d_min+ g[i_min][i].weight;
			}
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
