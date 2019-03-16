#include <iostream>
using namespace std;

int main() {

	int A[11] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int mas[5] = {0, 1, 3, 4, 3};

	for (int k = 1; k <= 4; ++k) {
		for (int j = 1; j <= mas[k]; ++j) {
			int t = A[2 * k - 1];
			A[2 *k - 1] = A[2 * k];
			A[2 * k] = A[2 * k + 1];
			A[2 * k + 1] = A[2 * k + 2];
			A[2 * k + 2] = t;
		}
	}

	for (int i = 1; i <= 10; ++i) {
		cout << A[i] << " ";
	}

	return 0;
}