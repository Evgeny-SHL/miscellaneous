#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m, f[100][100];
	char c;

	in >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			f[i][j] = 1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			in >> c;
			if (c == '*') {
				f[i][j] = 0;
				if (i >= 1) f[i-1][j] = 0;
				if (j < m-1) f[i][j+1] = 0;
				if (i < n-1) f[i+1][j] = 0;
				if (j >= 1) f[i][j-1] = 0;
			}
		}

	int s = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			s += f[i][j];

	out << s;

	in.close();
	out.close();
	return 0;
}