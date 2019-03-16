#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("marathon.in");
ofstream cout("marathon.out");

vector<int> x;
vector<int> y;

int main() {

	int n, a, b;
	int s = 0;

	cin >> n;

	x.resize(n + 1);
	y.resize(n + 1);

	cin >> x[1] >> y[1];
	for (int i = 2; i <= n; ++i) {
		cin >> x[i] >> y[i];
		s += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
	}

	int s1 = s;
	for (int i = 2; i <= n - 1; ++i) {
		s1 = min(s1, s - ((abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])) + (abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]))) + (abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1])));
	}

	cout << s1 << '\n';

	return 0;
}