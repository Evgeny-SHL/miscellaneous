#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	long double C, F, X;

	unsigned long long time = 0;
	unsigned long long dtime = 0;
	long double cookie = 0.0;
	long double prod = 1.0;
	cin >> C >> F >> X;
	while (ceil((C - cookie) / prod) + ceil((X - (cookie + prod * ceil((C - cookie) / prod) - C)) / (prod + F)) < ceil((X - cookie) / prod)) {
		dtime = ceil((C - cookie) / prod);
		time += dtime;
		cookie += prod * dtime - C;
		prod += F;
	}
	dtime = ceil((X - cookie) / prod);
	time += dtime;

	cout << time;

	return 0;
}