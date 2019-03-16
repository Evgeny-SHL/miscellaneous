#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ofstream fout("output.txt");

int power[45] = {
	800, 795, 750, 735, 700, 695, 690, 685, 675,
	655, 650, 615, 600, 600, 575, 550, 525, 525,
	520, 505, 500, 490, 490, 435, 360, 355, 350,
	340, 315, 300, 295, 290, 290, 270, 220, 210,
	210, 150, 150, 140, 140, 110, 110, 90, 90
};
vector<int> ans;
const int N = 45;
const int M = 15;
const int K = 1303;
vector<bool> used;
vector<int> cmp;

int main() {
	used.assign(N, false);
	cmp.assign(N, 0);
	ans.resize(N, -1);
	for (int num = 1; num <= M; ++num) {
		int x, y, z;
		x = y = z = 0;
		int d = 2500;
		for (int i = 0; i < N - 2; ++i) {
			if (used[i]) {
				continue;
			}
			for (int j = i + 1; j < N - 1; ++j) {
				if (used[j]) {
					continue;
				}
				for (int k = j + 1; k < N; ++k) {
					if (used[k]) {
						continue;
					}
					if (abs(power[i] + power[j] + power[k] - K) < d) {
						x = i;
						y = j;
						z = k;
						d = abs(power[i] + power[j] + power[k] - K);
					}
				}
			}
		}
		used[x] = used[y] = used[z] = true;
		ans[x] = ans[y] = ans[z] = num;
	}
	for (int i = 0; i < N; ++i) {
		fout << ans[i] << "\n";
	}

	return 0;
}