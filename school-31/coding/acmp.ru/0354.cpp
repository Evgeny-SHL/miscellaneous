#include <fstream>
#include <math.h>
using namespace std;

bool prime(int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int n, i = 2;
	in >> n;
	while (i <= sqrt((double) n)) {
		if (!(n % i)) {
			n /= i;
			out << i;
			if (n > 1) out << "*";
		}	else i++;
	}
	if (n > 1) out << n;

	in.close();
	out.close();
	return 0;
}