#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct point {
	double x, y;
	point(double param1 = 0.0, double param2 = 0.0) {
		x = param1;
		y = param2;
	}
};

double s_triangle(point A, point B, point C) {
	return abs(0.5 * ((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y)));
}

int main() {
	point A, B, C;
	double x, y, S;

	fin >> x >> y;
	A = point(x, y);

	fin >> x >> y;
	B = point(x, y);

	fin >> x >> y;
	C = point(x, y);

	S = s_triangle(A, B, C);

	fout << fixed;
	fout.precision(9);

	fout << S << "\n";

	return 0;
}