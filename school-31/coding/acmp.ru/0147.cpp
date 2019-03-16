#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, a = 1, b = 1, c = 1;
	in >> n;
	for(int i = 3; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	if (n > 0) out << c;
		else out << 0;

	in.close();
	out.close();
	return 0;
}