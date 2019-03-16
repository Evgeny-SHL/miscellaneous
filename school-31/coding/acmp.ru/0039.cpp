#include <iostream>
#include <fstream>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	int c[100];
	for(int i = 0; i < n; ++i)
		cin >> c[i];

	int s = 0, k = 0;
	do {
		int m = k;
		for(int j = k; j < n; j++)
			if (c[j]>c[m]) m = j;
		s += c[m]*(m+1-k);
		k = m+1;
	}	while (k<n);

	cout << s;

	return 0;
}