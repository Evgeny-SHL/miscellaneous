#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<long long> > > B;

int prv(int x) {
	return (x & (x + 1)) - 1;
}

int nxt(int x) {
	return (x | (x + 1));
}

void update(int x, int y, int z, int V, int N) {
	for (int i = x; i < N; i = nxt(i))
		for (int j = y; j < N; j = nxt(j))
			for (int k = z; k < N; k = nxt(k))
				B[i][j][k] += V;
}

void init(int N) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				update(i, j, k, 0, N);
}

long long rsq(int x, int y, int z) {
	long long res = 0;
	for (int i = x; i >= 0; i = prv(i))
		for (int j = y; j >= 0; j = prv(j))
			for (int k = z; k >= 0; k = prv(k))
				res += B[i][j][k];
	return res;
}

int main() {

	int N, M, K;
	long long S;

	cin >> N;
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		B[i].resize(N);
		for (int j = 0; j < N; ++j) {
			B[i][j].resize(N);
			for (int k = 0; k < N; ++k)
				B[i][j][k] = 0;
		}
	}
	init(N);

	int x, y, z, x1, y1, z1, x2, y2, z2;

	while (true) {
		cin >> M;
		if (M == 3) break;

		if (M == 1) {
			cin >> x >> y >> z >> K;
			update(x, y, z, K, N);
		} else if (M == 2) {
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			S = rsq(x2, y2, z2) -
			(rsq(x1 - 1, y2, z2) + rsq(x2, y1 - 1, z2) + rsq(x2, y2, z1 - 1)) +
			(rsq(x1 - 1, y1 - 1, x2) + rsq(x1 - 1, y2, z1 - 1) + rsq(x2, y1 - 1, z1 - 1)) -
			rsq(x1 - 1, y1 - 1, z1 - 1);
			cout << S << '\n';
		}
	}

	return 0;
}