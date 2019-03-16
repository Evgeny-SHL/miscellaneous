#include <iostream>
#include <fstream>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	int h, m, s[100];
	for(int i = 0; i < n; i++) {
		cin >> h >> m >> s[i];
		s[i] = s[i] + (m * 60) + (h * 3600);
	}

	bool f = 0;
	do {
		f = 1;
		for(int i = 0; i < n-1; i++)
			if (s[i]>s[i+1]) {
				f = 0;
				h = s[i];
				s[i] = s[i+1];
				s[i+1] = h;
			}
	}	while (!f);

	for(int i = 0; i < n; i++)
		cout << s[i] / 3600 << " "
			<< (s[i] / 60) % 60 << " "
			<< s[i] % 60 << endl;

	return 0;
}