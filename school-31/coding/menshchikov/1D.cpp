#include <fstream>
#include <stdlib.h>
using namespace std;

double EPS = 10e-4;

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int x0, x1, x2, x3, y0, y1, y2, y3;

	in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x0 >> y0;

	double s = 0.5 * abs((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3));

	double s1 = 0.5 * abs((x0-x3)*(y2-y3) - (x2-x3)*(y0-y3));
	double s2 = 0.5 * abs((x1-x3)*(y0-y3) - (x0-x3)*(y1-y3));
	double s3 = 0.5 * abs((x1-x0)*(y2-y0) - (x2-x0)*(y1-y0));

	if (abs(s1 + s2 + s3 - s) < EPS) out << "In";
	else out << "Out";

	return 0;
}