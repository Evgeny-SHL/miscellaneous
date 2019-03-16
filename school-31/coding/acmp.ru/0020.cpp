#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int n;
	in >> n;
	long int a[1000000], p, q;
	in >> p;
	for(long int i = 1; i < n; i++) {
		in >> q;
		a[i-1] = p - q;
		p = q;
	}

	bool f = (a[0] > 0) ? 1: 0;
	int k = 1, l = 1;
	for(long int i = 1; i < n-1; i++)
		if (((f) && (a[i] < 0)) || ((!f) && (a[i] > 0))) {
			k++;
			f = !f;
			if (k > l) l = k;
		}	else k = 1;

	l++;
	out << l;

	in.close();
	out.close();
	return 0;
}