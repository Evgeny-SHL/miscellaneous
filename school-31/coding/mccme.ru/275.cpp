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
	point A, M, N;
	double x, y;

	fin >> x >> y;
	A = point(x, y);

	fin >> x >> y;
	M = point(x, y);

	fin >> x >> y;
	N = point(x, y);

	if ((A.x - M.x) * (N.y - M.y) == (A.y - M.y) * (N.x - M.x) &&
		(A.x - M.x) * (N.x - M.x) >= 0 && (A.y - M.y) * (N.y - M.y) >= 0) {
		fout << "YES\n";
	} else {
		fout << "NO\n";
	}
	return 0;
}