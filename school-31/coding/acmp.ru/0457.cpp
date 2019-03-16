#include <fstream>
#include <cmath>
using namespace std;

long int mint(int n);
long int maxt(int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m, i = 0;
	in >> n;

	m = n;
	do {
		i++;
		n = m;
		m = maxt(n)-mint(n);
	}	while(n != m);

	out << m << endl << i-1;

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

	double m = 0;
	for(int i = 0; i < k; i++) {
		m += t[i]*pow(10,k-i-1);
	}

	return (long int) m;
}

long int maxt(int n) {
	int t[4], i = 0, k;
	if (n<1000) t[3] = 0;
	if (n<100) t[2] = 0;
	if (n<10) t[1] = 0;

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
	k = 4;

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