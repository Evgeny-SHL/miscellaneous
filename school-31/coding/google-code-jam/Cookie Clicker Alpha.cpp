#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const double EPS = 10E-7;

int main() {
	ifstream fin("B-large-practice.in");
	ofstream fout("B-large-practice.out");

	fout << fixed << setprecision(7);

	int T;
	double C, F, X;

	fin >> T;
	for (int t = 1; t <= T; ++t) {
		double time = 0;
		double cookie = 0;
		double prod = 2.0;
		fin >> C >> F >> X;
		while (C / prod + X / (prod + F) < X / prod) {
			time += C / prod;
			prod += F;
		}
		time += X / prod;
		fout << "Case #" << t << ": " << time << '\n';
	}

	return 0;
}