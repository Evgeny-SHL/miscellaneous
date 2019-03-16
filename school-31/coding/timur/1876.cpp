#include <iostream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;
	cout << max(2 * b + 40, 2 * a + 39);

	return 0;
}