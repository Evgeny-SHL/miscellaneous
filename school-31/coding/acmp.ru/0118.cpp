#include <fstream>
using namespace std;

bool srv(bool f[500], int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	bool f[500];
	int n, k;

	in >> n >> k;
	for(int i = 0; i < n; i++)
		f[i] = 1;

	int i, j = k % n - 1;
	do {
		i = 0;
		if (f[j]) {
			f[j] = 0;
		}
		do {
			j++;
			if (j >= n) j %= n;
			if (f[j]) i++;
		}	while(i != k);
	}	while(!srv(f,n));

	i = -1;
	do {
		i++;
	}	while(!f[i]);
	out << i+1;

	in.close();
	out.close();
	return 0;
}

bool srv(bool f[500], int n) {
	int k = 0;
	for(int i = 0; i < n; i++)
		if (f[i]) k++;
	return k == 1;
}