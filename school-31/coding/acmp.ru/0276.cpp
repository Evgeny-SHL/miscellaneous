#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m;
	in >> n >> m;
	int k;
	if (!n%m) k = (n - n%m +m)/m;
		else k = m;
	for(int i = 1; i <= k; i++) {
		if (i <= k - n%m) out << n / m << " ";
			else out << n/m + 1 << " ";
	}

	in.close();
	out.close();
	return 0;
}