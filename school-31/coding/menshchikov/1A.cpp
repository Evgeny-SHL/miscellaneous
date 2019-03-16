#include <fstream>
#include <math.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m;

	in >> m >> n;

	long p[100000];
	p[0] = 2;
	long l = 1;

	bool abs = true;
	for (int i = 2; i <= n; i++) {
		bool f = true;
		for (long j = 0; (j < l) && (p[j] <= sqrt(i)); j++) {
			if (i % p[j] == 0) {
				f = false;
				break;
			};
		}
		if (!f) continue;
		p[l++] = i;
		if (i >= m) {
			out << i << '\n';
			abs = false;
		}
	}
	if (abs) out << "Absent";

	return 0;
}