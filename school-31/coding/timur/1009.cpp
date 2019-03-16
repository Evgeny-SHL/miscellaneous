#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	if (N == 1) cout << K;
	else if (N == 2) cout << K * (K - 1);
	else cout << int(pow(K, N - 3)) * (K - 1) * (K * K - N + 2);

	return 0;
}