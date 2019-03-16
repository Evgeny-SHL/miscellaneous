#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string num;
	getline(cin, num);

	int dig[10];
	for (int i = 0; i < 10; i++)
		dig[i] = count(num.begin(), num.end(), i + '0');

	int m = 10;
	for (int i = 1; i < 10; i++) {
		if ((dig[i] % 2 == 1) && (i < m)) m = i;
		for (int j = 1; j <= dig[i] / 2; j++)
			cout << i;
	}
	if (m < 10) cout << m;
	for (int i = 9; i > 0; i--)
		for (int j = 1; j <= dig[i] / 2; j++)
			cout << i;

	return 0;
}