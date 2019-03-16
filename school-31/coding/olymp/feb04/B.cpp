#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

ifstream fin("partition.in");
ofstream fout("partition.out");

bool gen(int k, int prv, int sum) {
//	cout << k << " " << prv << " " << sum << "\n";
	if (k == 0 && sum == 0) {
		int res = ans[ans.size() - 1];
		for (int i = 1; i <  ans.size() - 1; ++i) {
			res ^= ans[i];
		}
		if (res == 0) {
			return true;
		}
		return false;
	} else if (k == 0) {
		return false;
	}
	bool flag = false;
	for (int i = min(prv, sum - k + 1); i >= 1; --i) {
		ans[k] = i;
		flag = flag || gen(k - 1, i, sum - i);
		if (flag) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, k;

	fin >> n >> k;
	ans.resize(k + 1);
	for (int i = n - k + 1; i >= 1; --i) {
		ans[k] = i;
		if (gen(k - 1, i, n - i)) {
			for (int i = 1; i <= k; ++i) {
				fout << ans[i] << " ";
			}
			fout << "\n";
			return 0;
		};
	}

	fout << "-1\n";

	return 0;
}
