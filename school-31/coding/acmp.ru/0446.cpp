#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m, t;
	char a[100][100];
	bool f = 1;

	in >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			in >> a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			in >> t;
			switch(t) {
				case 0:
					if (!(a[i][j] == '.')) f = 0;
					break;
				case 1:
					if (!(a[i][j] == '.' || a[i][j] == 'B')) f = 0;
					break;
				case 2:
					if (!(a[i][j] == '.' || a[i][j] == 'G')) f = 0;
					break;
				case 3:
					if (!(a[i][j] == '.' || a[i][j] == 'G' || a[i][j] == 'B')) f = 0;
					break;
				case 4:
					if (!(a[i][j] == '.' || a[i][j] == 'R')) f = 0;
					break;
				case 5:
					if (!(a[i][j] == '.' || a[i][j] == 'R' || a[i][j] == 'B')) f = 0;
					break;
				case 6:
					if (!(a[i][j] == '.' || a[i][j] == 'R' || a[i][j] == 'G')) f = 0;
					break;
			}
			if (!f) break;
		}

	if (f) out << "YES";
		else out << "NO";

	in.close();
	out.close();
	return 0;
}