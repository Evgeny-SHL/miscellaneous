#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int fact(int n) {
	assert(n >= 0);
	assert(n <= 5);
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}

int main() {
	int n;

	cin >> n;

	cout << fact(n) << "\n";

	return 0;
}