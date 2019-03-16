#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

long long arr[1000000];

int main() {

	int n = 0;
	long long x;
	while(cin >> x) {
		arr[n++] = x;
	}

	cout << fixed;
	cout << setprecision(4);
	for (int j = n - 1; j >= 0; --j) {
		cout << sqrt(arr[j]) << '\n';
	}

	return 0;
}