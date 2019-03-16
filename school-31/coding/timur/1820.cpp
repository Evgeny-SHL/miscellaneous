#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	if (k >= n) cout << 2;
	else cout << ceil(2.0 * n / k);

	return 0;
}