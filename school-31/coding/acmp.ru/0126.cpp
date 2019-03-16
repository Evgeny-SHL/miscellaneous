#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m[100][100], s = 0;

	in >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			in >> m[i][j];

	for(int i = 0; i < n-2; i++)
		for(int j = i+1; j < n-1; j++)
			for(int k = j+1; k < n; k++)
				if (!s || m[i][j] + m[i][k] + m[j][k] < s) s = m[i][j] + m[i][k] + m[j][k];

	out << s;

	in.close();
	out.close();
	return 0;
}