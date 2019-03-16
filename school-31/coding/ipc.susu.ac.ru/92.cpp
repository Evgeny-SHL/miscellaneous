#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > C;

int main() {

	int N, M, K, len;

	cin >> N >> M >> K;

	C.resize(N + M + 1);
	for (int n = 0; n <= N + M; ++n) {
		C[n].resize(n + 1);
		C[n][0] = 1;
		for (int k = 1; k <= n - 1; ++k) {
			C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
		}
		C[n][n] = 1;
	}

	K = (K - 1) % C[N + M][N] + 1;

	len = N + M;
	for (int i = 1; i <= len; ++i) {
		if (N > 0 && K <= C[N + M - 1][N - 1]) {
			cout << "D";
			N -= 1;
		} else {
			if (N > 0) {
				K -= C[N + M - 1][N - 1];
			}
			cout << "R";
			M -= 1;
		}
	}
	cout << "\n";

	return 0;
}