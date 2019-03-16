#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, t[100][100], q[100], k = 0;

	in >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			in >> t[i][j];
	for(int i = 0; i < n; i++)
		in >> q[i];

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if (t[i][j] && q[i] != q[j]) k++;
	out << k;

	in.close();
	out.close();
	return 0;
}