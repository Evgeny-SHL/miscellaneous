#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int xA, yA, x1, y1, x2, y2, dx, dy, xB, yB;
	in >> x1 >> y1 >> x2 >> y2 >> xA >> yA;
	dx = x2-x1;
	dy = y2-y1;

	if (dx) {
		xB = xA;
		yB = 2*y1 - yA;
	}	else if (dy) {
		xB = 2*x1 - xA;
		yB = yA;
	}

	out << xB << " " << yB;

	in.close();
	out.close();

	return 0;
}