/*
ID: ugnthes1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

	int n, m = 0, k = 0;
	string necklace;

	fin >> n >> necklace;
	necklace += necklace;

//	cout << necklace << endl;

	while (k < 2 * n) {
		int i = k, j = k + 1, s1 = 0, s2 = 0, l;

		char a = necklace[k];
		for (l = k; l >= 0 && a == 'w'; --l)
			a = necklace[l];
		if (l == -1) {
			for (l = 2 * n - 1; l > k && a == 'w'; --l)
				a = necklace[l];
		}
		if (a == 'w') {
			m = n;
			break;
		}

		char b = necklace[k + 1];
		for (l = k + 1; l < 2 * n && b == 'w'; ++l)
			b = necklace[l];
		if (l == 2 * n) {
			for (l = 0; l <= k && b == 'w'; ++l)
				b = necklace[l];
		}
		if (b == 'w') {
			m = n;
			break;
		}

		while ((i >= max(0, k + 1 - n)) && (necklace[i] == a || necklace[i] == 'w'))
			--i;
		s1 = k - i;

		while ((j <= min(2 * n - 1, n + i)) && (necklace[j] == b || necklace[j] == 'w'))
			++j;
		s2 = j - (k + 1);

//		cout << k << " " << char(necklace[k]) << char(necklace[k + 1]) << " " << s1 << " " << s2 << " " << i << " " << j << endl;

		++k;

		m = max(m, s1 + s2);
	}

	if (m == 0) m = n;

	fout << m << endl;

    return 0;
}