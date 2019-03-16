#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m[100][100];
	bool f = 1, t[101];
	in >> n;
	for(int i = 0; i < n*n; i++) {
		for(int j = 1; j <= n*n; j++)
			t[j] = 0;
		for(int j = 0; j < n*n; j++) {
			in >> m[i][j];
			t[m[i][j]] = 1;
		}
		for(int j = 1; j <= n*n; j++) {
			f = f && t[j];
			if (!f) break;
		}
		if (!f) break;
	}

	for(int j = 0; j < n*n; j++) {
		for(int i = 1; i <= n*n; i++)
			t[i] = 0;
		for(int i = 0; i < n*n; i++)
			t[m[i][j]] = 1;
		for(int i = 1; i <= n*n; i++) {
			f = f && t[i];
			if (!f) break;
		}
		if (!f) break;
	}


	for(int k = 0; k < n; k++) {
		for(int l = 0; l < n; l++) {
			for(int i = 1; i <= n*n; i++)
					t[i] = 0;
			for(int i = k*n; i < n*(k+1); i++)
				for(int j = l*n; j < n*(l+1); j++)
					t[m[i][j]] = 1;
			for(int i = 1; i <= n*n; i++) {
				f = f && t[i];
				if (!f) break;
			}
			if (!f) break;
		}
		if (!f) break;
	}

	if (f) out << "Correct";
		else out << "Incorrect";

	in.close();
	out.close();
	return 0;
}