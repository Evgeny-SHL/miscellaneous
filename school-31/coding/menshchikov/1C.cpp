#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(int a, int b) {
	return (b < a);
}

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	unsigned int n, p[10000], q[10000];
	int f[10001][10001];

	in >> n;
	for (unsigned int i = 0; i < n; i++) {
		in >> p[n - i - 1];
		q[i] = p[n - i - 1];
		f[0][i] = 0;
		f[i][0] = 0;
	}

	sort(q, q + n, comp);

	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			if (p[i] == q[j]) f[i+1][j+1] = f[i][j] + 1;
			else f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
		}
	}

	out << f[n][n] << '\n';
	unsigned int i = n, j = n;
	while (f[i][j] != 0) {
		while (f[i][j] == f[i-1][j]) i--;
		while (f[i][j] == f[i][j-1]) j--;
		out << p[i-1] << " ";
		i--;
		j--;
	}

	return 0;
}