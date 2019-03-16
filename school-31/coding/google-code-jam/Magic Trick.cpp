#include <iostream>
#include <fstream>
using namespace std;

int after[17], before[17];

int main() {
	ifstream fin("A-small-practice.in");
	ofstream fout("A-small-practice.out");

	int T, ans1, ans2, x, answer;
	bool finded, bad;

	fin >> T;

	for (int i = 1; i <= T; ++i) {
		fin >> ans1;
		for (int j = 1; j <= 16; ++j) {
			fin >> x;
			before[x] = (j - 1) / 4 + 1;
		}
		fin >> ans2;
		for (int j = 1; j <= 16; ++j) {
			fin >> x;
			after[x] = (j - 1) / 4 + 1;
		}

		finded = false;
		bad = false;
		for (int j = 1; j <= 16; ++j) {
			if (before[j] == ans1 && after[j] == ans2 && !finded) {
				finded = true;
				answer = j;
			} else if (before[j] == ans1 && after[j] == ans2) {
				bad = true;
			}
		}
		if (bad) {
			fout << "Case #" << i << ": Bad magician!" << '\n';
		} else if (finded) {
			fout << "Case #" << i << ": " << answer << '\n';
		} else {
			fout << "Case #" << i << ": " << "Volunteer cheated!" << '\n';
		}
	}

	return 0;
}