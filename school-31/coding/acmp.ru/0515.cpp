#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, x, y, x0, y0;
	double s = 0;

	in >> n;
	in >> x0 >> y0;
	s += sqrt((double) x0*x0 + y0*y0);
	for(int i = 2; i <= n; i++) {
		in >> x >> y;
		s += sqrt((double) pow(x-x0, 2) + pow(y-y0, 2));
		x0 = x;
		y0 = y;
	}
	s += sqrt((double) x*x + y*y);

	out << std::fixed;
	out << std::setprecision(3) << s;

	in.close();
	out.close();
	return 0;
}