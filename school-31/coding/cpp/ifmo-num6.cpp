#include <iostream>
#include <vector>
using namespace std;

vector<int> P;
vector<int> tacts;
const int N = 3;
const int startP[N] = {
	67, 31, 11
};
const int T = 3;


int main() {
	int t, cur, sum, old, fll, ans, tmn;

	ans = 0;
	tmn = 0;
	for (int k = 1; k <= 100; ++k) {
	//	cout << "\n" << k << "\n";
		P.assign(startP, startP + 3);
		tacts.assign(N, 0);
		sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += P[i];
		}
		t = 0;
		cur = 0;
		fll = 0;
		while (sum > 0) {
			if (P[cur] > k) {
				t += k;
				P[cur] -= k;
				sum -= k;
			} else if (P[cur] > 0) {
				t += P[cur];
				sum -= P[cur];
				P[cur] = 0;
			//	cout << t << "\n";
				fll += t;
			}
		//	cout << P[0] << " " << P[1] << " " << P[2] << " " << fll << "\n";
			if (sum > 0) {
				old = cur;
				do {
					cur = (cur + 1) % N;
				} while (P[cur] == 0);
				if (cur != old) {
					t += T;
				}
			}
		}
		cout << k << " " << fll << "\n";
		if (ans == 0 || fll < tmn) {
			ans = k;
			tmn = fll;
		}
	}

	cout << ans << "\n";

	return 0;
}