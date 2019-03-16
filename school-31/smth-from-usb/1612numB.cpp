#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> p;

class ShufflingCardsDiv2 {
	public:
	string shuffle(vector<int> permutation) {
		vector<int> a;
		vector<int> b;
		int n = permutation.size() / 2;
		a.resize(n);
		b.resize(n);
		for (int i = 0; i < n; ++i) {
			a[i] = permutation[2 * i];
			b[i] = permutation[2 * i + 1];
		}
		/*
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < n; ++i) {
			cout << b[i] << " ";
		}
		cout << '\n';
		*/
		int k1a = 0;
		int kna = 0;
		int k1b = 0;
		int knb = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] <= n) {
				++k1a;
			} else {
				++kna;
			}
			if (b[i] <= n) {
				++k1b;
			} else {
				++knb;
			}
		}
	//	cout << k1a << " " << kna << " " << k1b << " " << knb << '\n';
		if (k1a == (n / 2 + n % 2) && kna == n / 2 && k1b == n / 2 && knb == (n / 2 + n % 2)) {
			return "Possible";
		} else {
			return "Impossible";
		}
	}
};

int main() {
	ShufflingCardsDiv2 t;
	int n;
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	cout << t.shuffle(p);
	return 0;
}
