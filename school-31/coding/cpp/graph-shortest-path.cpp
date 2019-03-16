#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int a[21][21], b[21][21], n, m;

	in >> n >> m;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++)
			if (i && j) {
				in >> a[i][j];
				if (i > 1 && j > 1) b[i][j] = a[i][j] + min(b[i-1][j],b[i][j-1]);
					else if (i > 1 && j <= 1) b[i][j] = a[i][j] + b[i-1][j];
					else if (j > 1 && i <= 1) b[i][j] = a[i][j] + b[i][j-1];
					else if (i == 1 && j == 1) b[i][j] = a[i][j];
			}	else b[i][j] = 0;
		out << endl;
	}

	out << b[n][m];

	in.close();
	out.close();
	return 0;
}