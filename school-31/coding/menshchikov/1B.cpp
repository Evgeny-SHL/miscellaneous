#include <fstream>
#include <iostream>
using namespace std;

bool pl[24];
long a[24];

bool recurs(int n, long m, int depth, long sum, bool up) {
	if (sum == m) return true;
	if (depth == n) return false;

	bool f = recurs(n, m, depth + 1, sum + 2 * a[depth], true);
	if (f) {
		pl[depth] = true;
		return f;
	}

	f = recurs(n, m, depth + 1, sum, false);
	if (f) {
		pl[depth] = false;
		return f;
	}

	return false;
}

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	long m;
	in >> n >> m;

	long s = 0;
	for (int i = 0; i < n; i++) {
		in >> a[i];
		s -= a[i];
	}

	bool f = recurs(n, m, 0, s, false);

	if (f) {
		for (int i = 0; i < n; i++)
			pl[i] ? i > 0 ? out << "+" << a[i] : out << a[i] : out << "-" << a[i];
		out << "=" << m;
	} else out << "No solution";

	return 0;
}