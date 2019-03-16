#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const double EPS = 10E-7;

int main() {
	ifstream fin("C-small-practice.in");
	ofstream fout("C-small-practice.out");

	int T, R, C, M;

	fin >> T;
	for (int t = 1; t <= T; ++t) {
		fin >> R >> C >> M;
		fout << "Case #" << t << ":" << '\n';
		if ((R != 1 && C != 1 && M > R * C - 4 || M > R * C - 2) && (M + 1 != R * C))
			fout << "Impossible" << '\n';
		else {
			int k = 0;
			for (int i = 1; i <= R; ++i) {
				for (int j = 1; j <= C; ++j)
					if (k < M && (i < R - 1 || j < C - 1 || R == 1 || C == 1 || R * C == M + 1)) {
						fout << "*";
						++k;
					} else if (i != R || j != C)
						fout << ".";
					else
						fout << "c";
				fout << '\n';
			}
		}
	}

	return 0;
}