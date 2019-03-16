#include <fstream>
using namespace std;

bool srv(bool f[500], int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long long int n, a = 1, b = 1, c = a + b, i = 2;

	in >> n;
	do {
		c = a + b;
		a = b;
		b = c;
		i++;
	}	while (c < n);
	if (c == n) out << "1" << endl << i;
		else out << "0";

	in.close();
	out.close();
	return 0;
}

bool srv(bool f[500], int n) {
	int k = 0;
	for(int i = 0; i < n; i++)
		if (f[i]) k++;
	return k == 1;
}