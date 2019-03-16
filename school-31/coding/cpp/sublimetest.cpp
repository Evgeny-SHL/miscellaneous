#include <iostream>
using namespace std;

int sgn(int x) {
	return x > 0 ? 1 : x == 0 ? 0 : -1;
}

int main() {

	cout << "Hello!\n";

	int x;
	cin >> x;

	// вывод a
	cout << sgn(x) << "\n";


	return 0;
}