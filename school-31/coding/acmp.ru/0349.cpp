#include <fstream>
#include <math.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int m, n, p[100000], l = 1;
	p[0] = 2;
	in >> m >> n;
	for(long int i = 3; i <=n; i++) {
		bool f = 1;
		for(long int j = 0; p[j]*p[j] <= i; j++)
			if (!(i % p[j])) {
				f = 0;
				break;
			}
		if (f) {
			l++;
			p[l-1] = i;
		}
	}

	bool f = 1;
	for(long int i = 0; i < l; i++)
		if ((p[i] >= m) && (p[i] <= n)) {
			out << p[i] << " ";
			f = 0;
		}
	if (f) out << "Absent";

	in.close();
	out.close();
	return 0;
}