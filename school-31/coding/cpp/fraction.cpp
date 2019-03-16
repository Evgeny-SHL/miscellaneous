#include <iostream>
using namespace std;

int main() {
	int a, b, i = 2;
	cin >> a >> b;
	while(i <= min(a,b))
		if (a%i==0 && b%i==0) {
			a /= i;
			b /= i;
		}	else ++i;
	cout << a << " " << b;
	return 0;
}