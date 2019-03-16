#include <fstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int compare (const void *a, const void *b) {
  return (*(double*)a - *(double*)b);
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	char c;
	long int n;
	int a[100001], k;
	double b[100001];
	in >> n >> k;
	if (k >= n) out << "NO";
		else {
			for(long int i = 0; i < n; i++) {
				in >> c;
				a[i] = (c - 48);
				b[i] = 0;
			}

			for(long int i = 0; i < n-k+1; i++)
				for(int j = 0; j < k; j++)
					b[i] += (a[i+j]*pow(10,k-j-1));

			qsort(b,n-k+1,sizeof(double),compare);

			bool f = 0;
			for(long int i = 0; i < n-k; i++)
				if (b[i] == b[i+1]) {
					f = 1;
					break;
				}

			if (f) out << "YES";
				else out << "NO";
		}

	in.close();
	out.close();
	return 0;
}