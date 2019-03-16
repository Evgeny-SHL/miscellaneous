#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, k, m[100][100];
	in >> n >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			m[i][j] = 0;

	for(int i = 0; i < n; i++) {
		int p, q;
		in >> p;
		if (!p) break;
		in >> q;
		m[p-1][q-1] = 1;
		for(int j = 0; j < n; j++)
			if (m[j][p-1]) m[j][q-1] = 1;
		for(int j = 0; j < n; j++)
			if (m[q-1][j]) m[p-1][j] = 1;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			if (m[i][j]) {
				for(int k = 0; j < n; j++)
					if (m[k][i]) m[k][j] = 1;
				for(int k = 0; j < n; j++)
					if (m[j][k]) m[i][k] = 1;
			}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			out << m[i][j];
		out << endl;
	}
	out << endl;
	int s = 0;
	for(int j = 0; j < n; j++)
		s += m[k-1][j];

	if (s == n-1) out << "Yes";
		else out << "No";

	in.close();
	out.close();
	return 0;
}