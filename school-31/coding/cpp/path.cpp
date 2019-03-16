#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, s, d[10], m[10][10], p = -1, k = 0;
	bool u[10];

	in >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			in >> m[i][j];
	in >> s;

	for(int i = 0; i < n; i++) {
		d[i] = 32000;
		u[i] = 0;
	}
	d[s-1] = 0;

	for(int i = 0; i < n; i++){
		p = -1;
		for(int j = 0; j < n; j++)
			if ((p == -1 || d[j] < d[p]) && !u[j]) p = j;
		u[p] = 1;
		for(int j = 0; j < n; j++)
			if (m[p][j]) d[j] = min(d[j],d[p]+m[p][j]);
	}

	for(int i = 0; i < n; i++)
		out << d[i] << endl;

	in.close();
	out.close();
	return 0;
}