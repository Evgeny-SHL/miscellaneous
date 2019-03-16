#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int n, m = 1;
	int k, s = 0;
	in >> n >> k;
	while (n > 0) {
		s += n % k;
		m *= n % k;
		n /= k;
	}

	out << m - s;

	in.close();
	out.close();
	return 0;
}