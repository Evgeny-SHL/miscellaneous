#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("cinema.in");
ofstream fout("cinema.out");

struct film {
	long long a, b, c;
	int ind;
	film(long long p1 = 0, long long p2 = 0, long long p3 = 0, int i = 0) {
		a = p1;
		b = p2;
		c = p3;
		ind = i;
	}
};

vector<film> b, c;

bool comp1(film x, film y) {
	if (x.b - x.a > y.b - y.a) {
		return true;
	}
	return false;
}

bool comp2(film x, film y) {
	if (x.c - x.a > y.c - y.a) {
		return true;
	}
	return false;
}


int main() {
	int n;
	long long x, y, z;
	long long ans;

	fin >> n;

	b.resize(n);
	for (int i = 0; i < n; ++i) {
		fin >> x >> y >> z;
		b[i] = film(x, y, z, i + 1);
	}

	c.assign(b.begin(), b.end());

	sort(b.begin(), b.end(), comp1);
	sort(c.begin(), c.end(), comp2);


	ans = 0;
	if (b[0].ind != c[0].ind) {
		ans += b[0].b + c[0].c;
		for (int i = 1; i < n; ++i) {
			if (b[i].ind != c[0].ind) {
				ans += b[i].a;
			}
		}
		fout << ans << '\n';
		fout << b[0].ind << " " << c[0].ind << '\n';
	} else {
		if (b[0].b + c[1].c > c[0].c + b[1].b) {
			ans += b[0].b + c[1].c;
			for (int i = 1; i < n; ++i) {
				if (b[i].ind != c[1].ind) {
					ans += b[i].a;
				}
			}
			fout << ans << '\n';
			fout << b[0].ind << " " << c[1].ind << '\n';
		} else {
			ans += c[0].c + b[1].b;
			for (int i = 1; i < n; ++i) {
				if (c[i].ind != b[1].ind) {
					ans += c[i].a;
				}
			}
			fout << ans << '\n';
			fout << b[1].ind << " " << c[0].ind << '\n';
		}
	}

	return 0;
}

