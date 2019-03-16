#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > score;

int main() {

	int a, b;
	cin >> a >> b;

	if (a % 2 == 0 && b % 2 == 0) cout << (b - a) / 2;
	else if (a % 2 == 0 || b % 2 == 0) cout << (b - a + 1) / 2;
	else cout << (b - a) / 2 + 1;

	return 0;
}