#include <vector>
#include <iostream>
using namespace std;

vector<int> x;
vector<int> y;

class TrianglesContainOriginEasy {
	struct vctr {
		int x, y;
		vctr(int a = 0, int b = 0) {
			x = a;
			y = b;
		}
	};

	bool sgn(vctr a, vctr b) {
		return (a.x * b.y - a.y * b.x) > 0;
	}
	
	public:
	int count(vector<int> x, vector<int> y) {
		int n = x.size();
		int m = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j + 1; k < n; ++k) {
					vctr v1 = vctr(x[i] - x[j], y[i] - y[j]);
					vctr v2 = vctr(x[j] - x[k], y[j] - y[k]);
					vctr v3 = vctr(x[k] - x[i], y[k] - y[i]);
					vctr u1 = vctr(-x[j], -y[j]);
					vctr u2 = vctr(-x[k], -y[k]);
					vctr u3 = vctr(-x[i], -y[i]);
					if (sgn(v1, u1) == sgn(v2, u2) && (sgn(v2, u2) == sgn(v3, u3))) {
						++m;
					}
				}
			}
		}
		return m;
	}
};

int main() {
	TrianglesContainOriginEasy t;
	int n;
	cin >> n;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> y[i];
	}
	cout << t.count(x, y);
	return 0;
}
