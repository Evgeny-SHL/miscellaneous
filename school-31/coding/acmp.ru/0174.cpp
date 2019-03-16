#include <iostream>
#include <fstream>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	double m[40];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> m[i];
	double a;
	cin >> a;

	bool f = 0;
	do {
		f = 1;
		for(int i = 0; i < n-1; i++)
			if (m[i]>m[i+1]) {
				f = 0;
				int t = m[i];
				m[i] = m[i+1];
				m[i+1] = t;
			}
	}	while(!f);

	for(int i = 0; i < n; i++) {
		if (a < m[i]) a = (a / 2) + (m[i]/2);
	}

	printf("%.6f", a);

	return 0;
}