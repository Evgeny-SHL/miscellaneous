#include <iostream>
using namespace std;

int main() {

	int n, m;

	cin >> n >> m;

	if (m * n % 2 == 0) cout << "[:=[first]";
	else cout << "[second]=:]";

	return 0;
}