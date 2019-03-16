#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int t, n, m, p[100][100];
	in >> t;
	for(int k = 1; k <= t; k++) {
		in >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				in >> p[i][j];
		bool f = 1;
		for(int i = 0; i < n-1; i++) {
			for(int j = 0; j < m-1; j++) {
				f = (p[i][j] + p[i+1][j] + p[i][j+1] + p[i+1][j+1]) % 4;
				if (!f) break;
			}
			if (!f) break;
		}
		if (f) out << "YES" << endl;
			else out << "NO" << endl;
	}

	in.close();
	out.close();
	return 0;
}