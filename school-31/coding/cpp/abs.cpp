#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n = - ((long long)1 << 63);
	cout << n << "\n";
	cout << abs(n);
	return 0;
}