#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int m[200000], k[200000], n;
	in >> n;
	for(long int i = 0; i < n; i++) {
		in >> m[i];
		k[i] = m[i];
	}

	qsort(k,n,sizeof(long int),compare);

	long int p = k[0], c = k[0];
	long int mx = 1, l = 1;
	for(long int i = 1; i < n; i++) {
		long int d = k[i];
		if (d != c) {
			c = d;
			l = 1;
		}	else l++;
		if (l > mx) {
			p = d;
			mx = l;
		}	else if (l == mx) {
			if (p > d) p = d;
		}
	}

	for(long int i = 0; i < n; i++)
		if (m[i] != p) out << m[i] << " ";
	for(long int i = 1; i <= mx; i++)
		out << p << " ";

	in.close();
	out.close();

	return 0;
}