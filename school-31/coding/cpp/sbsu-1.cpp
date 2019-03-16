#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string b;
	int n, m;
	char ind = 0; // индекс максимальной цифры среди первых m + 1
	cin >> a >> n >> m;
	// находим индекс максимальной цифры
	for (int i = 0; i <= m; ++i) {
		if (a[i] > a[ind]) {
			ind = i;
		}
	}
	// удаляем все цифры до нее
	for (int i = 0; i < ind; ++i) {
		a[i] = '*';
		m--;
	}
	// удаляем цифру, если следующая больше
	for (int i = ind + 1; (i < n - 1) && (m > 0); ++i) {
		if (a[i] < a[i + 1]) {
			a[i] = '*';
			m--;
		}
	}
	// если мы не удаляли цифры (все цифры по убыванию), то придется удалить последние
	for (int i = n - 1; (i >= 0) && (m > 0); --i) {
		a[i] = '*';
		m--;
	}
	// создаем число-ответ
	b = "";
	for (int i = 0; i < n; ++i) {
		if (a[i] != '*') {
			b += a[i];
		}
	}
	cout << b << '\n';
	return 0;
}