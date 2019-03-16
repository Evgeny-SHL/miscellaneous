#include <fstream>
#include <vector>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<unsigned long long> f;

int main() {

	int n;

	cin >> n;
	f.resize(n + 1);

	f[1] = 3;
	for (int i = 2; i <= n; ++i) {
		f[i] = 2 * f[i - 1];
	}

	cout << f[n] << '\n';

	return 0;
}