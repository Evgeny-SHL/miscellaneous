#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const long long INF = 2009000999LL;

ifstream in("input.txt");
ofstream out("output.txt");

const int MAX_N = 20010;
const int MAX_M = 60030;
int heap[MAX_M];
int h_size = 0;

struct edge {
	int finish, weight;
	edge(int fin = 0, int wei = 0) {
		finish = fin;
		weight = wei;
	}
};

long long dist[MAX_N];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int comp(int a, int b) {
	return dist[a] < dist[b];
}

int h_comp(int a, int b) {
	return comp(heap[a], heap[b]);
}

void exch(int a, int b) {
	swap(heap[a], heap[b]);
}

void up_main(int ind) {
	while ((ind > 1) && h_comp(ind, ind / 2)) {
		exch(ind, ind / 2);
		ind /= 2;
	}
}

void down_main(int ind) {
    int i;
	while ((i=2*ind) <= h_size) {
		if (i < h_size && h_comp(i+1, i)) i++;
		if (!h_comp(i, ind)) break;
        exch(i, ind);
        ind = i;
	}
}

int ext() {
	exch(1, h_size--);
	down_main(1);
	return heap[h_size+1];
}

void ins(int index) {
	heap[++h_size] = index;
	up_main(h_size);
}

void build(int amount) {
	for (int i = 1; i <= amount; i++)
		heap[i] = i-1;
	h_size = amount;
	for (int i = h_size / 2; i >= 1; i--) {
		down_main(i);
	}
}

vector<vector<edge> > g;

void dijkstra(int start, int n) {
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