#include <iostream>
#include <fstream>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	long int m[201], n;
	short int t;

	for(int i = 0; i < 201; i++)
		m[i] = 0;

	cin >> n;
	for(long int i = 0; i < n; i++) {
		cin >> t;
		m[t+100]++;
	}

	for(int i = 0; i < 201; i++)
		for(long int j = 1; j <= m[i]; j++)
			cout << i-100 << " ";

	return 0;
}