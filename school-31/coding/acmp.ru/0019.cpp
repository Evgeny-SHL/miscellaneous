#include <fstream>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int a[8][8];
	for(int i = 0; i <= 7; i++)
		for(int j = 0; j <= 7; j++)
			a[i][j] = 0;
	char t1[3], t2[3], t3[3];
	in >> t1 >> t2 >> t3;

	int fr[2], ld[2], kn[2];
	fr[0] = t1[0]-65;
	fr[1] = t1[1]-49;
	ld[0] = t2[0]-65;
	ld[1] = t2[1]-49;
	kn[0] = t3[0]-65;
	kn[1] = t3[1]-49;
	a[fr[0]][fr[1]] = 1;
	a[ld[0]][ld[1]] = 1;
	a[kn[0]][kn[1]] = 1;;

	int k = -3;
	for(int i = 0; i <= 7; i++) {
		for(int j = 0; j <= 7; j++) {
			if (i == fr[0] || j == fr[1]) a[i][j] = 1;
			if (i == ld[0] || j == ld[1]) a[i][j] = 1;
			if (abs(fr[0]-i) == abs(fr[1]-j)) a[i][j] = 1;
			if (abs(kn[0]-i) * abs(kn[1]-j) == 2) a[i][j] = 1;
			out << a[i][j];
			k += a[i][j];

		}
		out << endl;
	}

	out << k;

	in.close();
	out.close();
	return 0;
}