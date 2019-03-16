#include <fstream>
#include <math.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, x1, y1, x2, y2;
	double q, l1, l2;
	bool f = 1;
	in >> n >> q;

	for(int i = 1; i <= n; i++) {
		in >> x1 >> y1 >> x2 >> y2;
		l1 = sqrt((double)(x1*x1 + y1*y1));
		l2 = sqrt((double)(x2*x2 + y2*y2));
		f = f && (l2 <= q*l1);
	}

	if (f) out << "Yes";
		else out << "No";

	in.close();
	out.close();
	return 0;
}