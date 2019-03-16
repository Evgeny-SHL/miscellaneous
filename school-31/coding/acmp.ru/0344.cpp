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

	long int n, a[100000], b[100000];
	in >> n;
	for(long int i = 0; i < n; i++) {
		in >> a[i];
		b[i] = a[i];

	}

	qsort(b,n,sizeof(long int),compare);
	long int  x1 = 0, x2 = 1, dx = b[x2] - b[x1];
	for(long int i = 0; i < n-1; i++)
		if (b[i+1] - b[i] < dx) {
			x1 = i;
			x2 = i+1;
			dx = b[x2] - b[x1];
		}

	long int i = -1;
	do {
		i++;
	}	while (a[i] != b[x1]);
	long int j = -1;
	do {
		j++;
	}	while (a[j] != b[x2] );

	out << dx << endl << i+1 << " " << j+1;

	in.close();
	out.close();

	return 0;
}