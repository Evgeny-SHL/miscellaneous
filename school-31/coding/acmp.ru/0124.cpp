#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m, t[100][100], s, f;

	in >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++) {
			t[i][j] = 0;
			t[j][i] = 0;
		}

	for(int i = 1; i <= m; i++){
		in >> s >> f;
		t[s-1][f-1] = 1;
		t[f-1][s-1] = 1;
	}

	for(int i = 0; i < n; i++) {
		s = 0;
		for(int j = 0; j < n; j++)
			s += t[i][j];
		out << s << " ";
	}

	in.close();
	out.close();
	return 0;
}