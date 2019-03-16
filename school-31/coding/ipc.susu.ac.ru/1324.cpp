#include <fstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int Amount = 187;
int prime[Amount] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
	41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
	97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
	157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
	227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
	283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359,
	367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
	439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
	509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593,
	599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
	661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743,
	751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
	829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
	919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
	1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
	1087, 1091, 1093, 1097, 1103, 1109, 1117
};
map< pair< pair<int, int>, int>, int > cash;
vector< vector<int> > dp;

int slow(int n, int k, int prev) {
	pair< pair<int, int>, int> c = make_pair(make_pair(n, k), prev);
	if (cash.find(c) != cash.end()) {
		return cash[c];
	}
	if (k == 0 && n == 0) {
		return 1;
	} else if (k == 0) {
		return 0;
	}
	int res = 0;
	for (int p = prev + 1; (p < Amount && prime[p] <= n); ++p) {
		res += slow(n - prime[p], k - 1, p);
	}
	cash[c] = res;
	return res;
}

int stupid(int n, int k, int prev) {
	if (k == 0 && n == 0) {
		return 1;
	} else if (k == 0) {
		return 0;
	}
	int res = 0;
	for (int p = prev + 1; (p < Amount && prime[p] <= n); ++p) {
		res += stupid(n - prime[p], k - 1, p);
	}
	return res;
}

int fast(int n, int k) {
	dp.resize(n + 1, vector<int>(k + 1));
	dp[0][0] = 1;
	for (int p: prime) {
		for (int w = n; w >= p; --w) {
			for (int t = 1; t <= k; t++) {
				dp[w][t] += dp[w - p][t - 1];
			}
		}
	}

	return dp[n][k];
}

int main() {
	int n, k;

	cin >> n >> k;

//	cout << fast(n, k) << "\n";
//	cout << stupid(n, k, -1) << "\n";
	cout << slow(n, k, -1) << "\n";

	return 0;
}