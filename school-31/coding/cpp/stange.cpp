#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

vector< vector<int> > mas;

int main() {
	ofstream fout("output.txt");
	int ans;
	mas.resize(6);
	for (int i = 1; i <= 5; ++i) {
		mas[i].resize(6);
	}
	ans = 0;
	for (int mask = 0; mask < (1 << 6); ++mask) {
		bitset<25> b(mask);
		int k = 0;
		for (int i = 1; i <= 5; ++i) {
			for (int j = 1; j <= 5; ++j) {
				mas[i][j] = b[k++];
			}
		}
		int i, j, dx, dy;
		i = 1;
		dx = 0;
		dy = 0;
		while (i <= 5) {
			j = 1;
			while (j <= 5) {
				if (mas[i][j] == 1) {
					if (i < j) {
						dx += i;
						dy -= j;
					} else if (i > j) {
						dx -= i;
						dy += j;
					}
				}
				++j;
			}
			++i;
		}
		if (dx == -1 && dy == -1) {
			++ans;
			fout << b << " " << mask << "\n";
			for (int i = 1; i <= 5; ++i) {
				for (int j = 1; j <= 5; ++j) {
					fout << mas[i][j] << " \n"[j == 5];
				}
			}
		}
	}
	// 1100011000001000001000001
	bitset<26> b((unsigned long)59510849);
	fout << b << "\n";
	fout << ans << "\n";
	return 0;
}