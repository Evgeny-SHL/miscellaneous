#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double Max = 1000.0;
const double Eps = 1e-15;
const double Delt = 5e-6;
const int Its = 70;

int n;

vector<double> x, y, z;

double len(double x, double y, double z, double x1, double y1, double z1) {
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
}

double energy(double px, double py, double pz) {
	double maxr = 0.0;
	double l;
	for (int i = 0; i < n; ++i) {
		l = len(px, py, pz, x[i], y[i], z[i]);
		maxr = max(maxr, l * l * l);
	}
	return maxr;
}

int main() {

	cin >> n;

	x.resize(n);
	y.resize(n);
	z.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> z[i];
	}

	double lx, rx,	ly, ry, lz, rz;
	double mx1, mx2, my1, my2, mz1, mz2;
	double cx1, cx2, cy1, cy2, cz1, cz2;
	double cz11, cz12, cz21, cz22;
	double bx, by, bz;

	lx = -Max;
	rx = Max;
	for (int p = 0; p < Its; ++p) {
		mx1 = lx + (rx - lx) / 3.0;
		mx2 = rx - (rx - lx) / 3.0;

		ly = -Max;
		ry = Max;
		for (int q = 0; q < Its; ++q) {
			my1 = ly + (ry - ly) / 3.0;
			my2 = ry - (ry - ly) / 3.0;

			lz = -Max;
			rz = Max;
			for (int r = 0; r < Its; ++r) {
				mz1 = lz + (rz - lz) / 3.0;
				mz2 = rz - (rz - lz) / 3.0;

				if (energy(mx1, my1, mz1) < energy(mx1, my1, mz2) + Eps) {
					rz = mz2;
				} else {
					lz = mz1;
				}
			}
			cz11 = lz;

			lz = -Max;
			rz = Max;
			for (int r = 0; r < Its; ++r) {
				mz1 = lz + (rz - lz) / 3.0;
				mz2 = rz - (rz - lz) / 3.0;

				if (energy(mx1, my2, mz1) < energy(mx1, my2, mz2) + Eps) {
					rz = mz2;
				} else {
					lz = mz1;
				}
			}
			cz12 = lz;

			if (energy(mx1, my1, cz11) < energy(mx1, my2, cz12) + Eps) {
				cy1 = my1;
				cz1 = cz11;
				ry = my2;
			} else {
				cy1 = my2;
				cz1 = cz12;
				ly = my1;
			}
		}

		ly = -Max;
		ry = Max;
		for (int q = 0; q < Its; ++q) {
			my1 = ly + (ry - ly) / 3.0;
			my2 = ry - (ry - ly) / 3.0;

			lz = -Max;
			rz = Max;
			for (int r = 0; r < Its; ++r) {
				mz1 = lz + (rz - lz) / 3.0;
				mz2 = rz - (rz - lz) / 3.0;

				if (energy(mx2, my1, mz1) < energy(mx2, my1, mz2) + Eps) {
					rz = mz2;
				} else {
					lz = mz1;
				}
			}
			cz21 = lz;

			lz = -Max;
			rz = Max;
			for (int r = 0; r < Its; ++r) {
				mz1 = lz + (rz - lz) / 3.0;
				mz2 = rz - (rz - lz) / 3.0;

				if (energy(mx2, my2, mz1) < energy(mx2, my2, mz2) + Eps) {
					rz = mz2;
				} else {
					lz = mz1;
				}
			}
			cz22 = lz;

			if (energy(mx2, my1, cz21) < energy(mx2, my2, cz22) + Eps) {
				cy2 = my1;
				cz2 = cz21;
				ry = my2;
			} else {
				cy2 = my2;
				cz2 = cz22;
				ly = my1;
			}
		}

		if (energy(mx1, cy1, cz1) < energy(mx2, cy2, cz2) + Eps) {
			rx = mx2;
		} else {
			lx = mx1;
		}
	}

	bx = lx;
	if (energy(bx, cy1, cz1) < energy(bx, cy2, cz2) + Eps) {
		by = cy1;
		bz = cz1;
	} else {
		by = cy2;
		bz = cz2;
	}

	cout << fixed;
	cout.precision(5);
	if (abs(bx) < Delt) {
		bx = 0.0;
	}
	if (abs(by) < Delt) {
		by = 0.0;
	}
	if (abs(bz) < Delt) {
		bz = 0.0;
	}

	cout << bx << " " << by << " " << bz << "\n";

	return 0;
}