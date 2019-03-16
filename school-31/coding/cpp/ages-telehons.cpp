#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int n = 15;
	srand(time(NULL));
	// телефон
	/*for (int i = 1; i <= n; ++i) {
		cout << (long long)80000000000 + (long long)((long long) rand() * (long long)999983 * (long long)999983) % (long long)10000000009 << " ";
		cout << '\n';
	}*/
	// возраст
	/*for (int i = 1; i <= n; ++i) {
		cout << 18 + rand() % 32 << " ";
		cout << '\n';
	}*/
	// цена
	/*for (int i = 1; i <= n; ++i) {
		cout << (25000.0 + ((long long)rand() * (long long)(1e9 + 7)) % 25000) / 100;
		cout << '\n';
	}*/
	// количество
	for (int i = 1; i <= n; ++i) {
		cout << 1 + rand() % 100;
		cout << '\n';
	}
	// год издания
	/*for (int i = 1; i <= n; ++i) {
		cout << 1996 + rand() % 16;
		cout << '\n';
	}*/
	// id
	/*for (int i = 1; i <= n; ++i) {
		cout << rand() % 15;
		cout << '\n';
	}*/
	return 0;
}