#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> sum(vector<int> a, vector<int> b) {

	vector<int> c(30);
	c[0] = 0;
	for (int i = 0; i < 29; ++i) {
		c[i + 1] = (c[i] + a[i] + b[i]) / 10;
		c[i] = (c[i] + a[i] + b[i] + 10) % 10;
	}

	return c;
}

void write(vector<int> a) {

	int k = 29;
	while (k >= 0 && a[k] == 0)
		--k;
	while (k >= 0) {
		cout << a[k];
		--k;
	}
	cout << '\n';
}

int main() {

	string seq;
	cin >> seq;

	int n = seq.length();
	vector<int> s(n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = int(seq[i - 1] - '0');

	vector<vector<int> > d(n + 1);
	for (int i = 0; i <= n; ++i) {
		d[i].resize(30);
		for (int j = 0; j < 30; ++j) {
			d[i][j] = 0;
		}
	}
	d[0][0] = 1;


	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 30; ++j)
			d[i][j] = d[i - 1][j];
		if (i > 1 && s[i - 1] != 0 && (s[i - 1] * 10 + s[i] <= 33))
			d[i] = sum(d[i], d[i - 2]);
	}

	write(d[n]);

	return 0;
}