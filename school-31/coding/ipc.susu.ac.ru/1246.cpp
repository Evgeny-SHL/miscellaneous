#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;

int main() {
	int a, b;
	cin >> a >> b;

	if (a <= b)
		for (int i = a; i <= b; ++i)
			cout << i << '\n';
	else
		for (int i = a; i >= b; --i)
			cout << i << '\n';

}