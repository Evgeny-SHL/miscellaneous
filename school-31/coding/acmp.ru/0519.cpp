#include <fstream>
#include <math.h>
using namespace std;

long int mint(int n);
long int maxt(int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int n;
	in >> n;
	out << mint(n) << " " << maxt(n);

	in.close();
	out.close();
	return 0;
}

long int mint(int n) {
	int t[10], i = 0, k;
	if (n == 0) {
		t[0] = 0;
		k = 1;
	} else {
		while (n > 0) {
			t[i] = n % 10;
			n /= 10;
			i++;
		}
		k = i;
	}

	bool f;
	do {
		f = 1;
		for(int i = 0; i < k-1; i++)
			if (t[i] > t[i+1]) {
				f = 0;
				int l = t[i];
				t[i] = t[i+1];
				t[i+1] = l;
			}
	}	while (!f);

	if (!t[0] && k > 1) {
		i = 0;
		do {
			i++;
		}	while ((!t[i]) && (i < k));
			int l = t[i];
			t[i] = t[0];
			t[0] = l;
	}

	double m = 0;
	for(int i = 0; i < k; i++) {
		m += t[i]*pow(10,k-i-1);
	}

	return (long int) m;
}

long int maxt(int n) {
	int t[10], i = 0, k;
	if (n == 0) {
		t[0] = 0;
		k = 1;
	} else {
		while (n > 0) {
			t[i] = n % 10;
			n /= 10;
			i++;
		}
		k = i;
	}

	bool f;
	do {
		f = 1;
		for(int i = 0; i < k-1; i++)
			if (t[i] < t[i+1]) {
				f = 0;
				int l = t[i];
				t[i] = t[i+1];
				t[i+1] = l;
			}
	}	while (!f);

	double m = 0;
	for(int i = 0; i < k; i++) {
		m += t[i]*pow(10,k-i-1);
	}

	return (long int) m;
}