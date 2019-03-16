#include <fstream>
#include <vector>
using namespace std;

ifstream cin("cowjog.in");
ofstream cout("cowjog.out");

vector<int> v;

int main() {

	int n, a;
	int k = 1;

	cin >> n;

	v.resize(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> a >> v[i];
	}

	for (int i = n - 1; i >= 1; --i) {
		if (v[i] > v[i + 1]) {
			v[i] = v[i + 1];
		} else {
			++k;
		}
	}

	cout << k;

	return 0;
}