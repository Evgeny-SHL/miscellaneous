#include <fstream>
#include <math.h>
using namespace std;

bool prime(int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, i = 1, j;
	in >> n;
	do {
		i++;
		if (prime(i)) {
			j = i-1;
			do {
				j++;
			}	while ((i+j < n) || !(prime(j)));
		}
	}	while ((i+j != n) || !prime(i) || !prime(j));

	out << i << " " << j;

	in.close();
	out.close();
	return 0;
}

bool prime(int n) {
	bool f = 1;
	for(int i = 2; i <= sqrt((double) n); i++)
		if (!(n % i)) {
			f = 0;
			break;
		}
	return f;
}