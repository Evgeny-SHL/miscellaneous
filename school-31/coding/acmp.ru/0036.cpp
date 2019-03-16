#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	unsigned int n, k = 0;;
	in >> n;
	for(long int i = n+1; i < 2*n; i++) {
		bool f = (i % 2);
		if (f) {
			for(int j = 3; j <= sqrt((double) i); j += 2) {
				f = f && (i % j);
				if (!f) break;
			}
		}
		if (f) k++;
	}
	out << k;

	in.close();
	out.close();
	return 0;
}