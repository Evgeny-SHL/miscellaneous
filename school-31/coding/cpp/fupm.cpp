#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <stdio.h>
using namespace std;

int main() {

	long double sum, x;
	cout.precision(20);
	cout << fixed;
	sum = 0.0L;
	while (scanf("%Lf", &x) != EOF) {
		sum += x;
	}
	printf("%.50Lf", sum);

	return 0;
}