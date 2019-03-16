#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int n;
	int k = 0;
	in >> n;

	while (n > 0) {
		k += n % 2;
		n /= 2;
	}

	out << k;

	return 0;
}