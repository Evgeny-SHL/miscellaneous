#include <fstream>
using namespace std;

int sum(int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int n, s = 1;
	in >> n;

	for(long int i = 1; i <= n; i++)
		if (!(n % i) && sum(i) > sum(s)) {
			s = i;
		}

	out << s;

	in.close();
	out.close();
	return 0;
}

int sum(int n) {
	int s = 0;
	while (n>0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}