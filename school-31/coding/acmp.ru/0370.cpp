#include <fstream>
#include <stdlib.h>
using namespace std;



int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	unsigned int n;
	int x1, y1, x2, y2, x3, y3;
	double s = 0;
	in >> n >> x1 >> y1 >> x2 >> y2;
	for(unsigned int i = 3; i <= n; i++) {
		in >> x3 >> y3;
		s += 0.5*abs((x2-x1)*(y3-y1) - (y2-y1)*(x3-x1));
		x2 = x3;
		y2 = y3;
	}

	out << s;

	in.close();
	out.close();
	return 0;
}