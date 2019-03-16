#include <fstream>
#include <vector>
using namespace std;

ofstream fout("gen1423.txt");

const int MAX_K = 9;
vector< vector<int> > good;

void cmp_srch(int k, int num, int sum, int mul) {
	if (k < MAX_K) {
		int num1, sum1, mul1;
		for (int d = 2; d <= 9; ++d) {
			num1 = num * 10 + d;
			sum1 = sum + d;
			mul1 = mul * d;
			if (num1 % sum1 == 0 && num1 % mul1 == 0) {
				good[k].push_back(num1);
			}
			cmp_srch(k + 1, num1, sum1, mul1);
		}
	}
}

int main() {
	good.resize(10);
	cmp_srch(0, 0, 0, 1);

	for (int i = 0; i < MAX_K; ++i) {
		fout << good[i].size() << '\n';
	//	for (int j = 0; j < good[i].size(); ++j) {
	//		fout << good[i][j] << ", ";
	//	}
	//	fout << '\n';
	}

	return 0;
}