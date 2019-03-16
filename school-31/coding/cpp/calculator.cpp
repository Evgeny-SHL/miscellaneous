#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int a[1000], b[1000], res[2000], l1, l2, lmax;
	string s;

	getline(in,s);
	l1 = s.size();
	for(int i = 0; i < l1; i++) {
		a[i] = s[l1-i-1]-48;
		res[i] = 0;
	}
	getline(in,s);
	l2 = s.size();
	for(int i = 0; i < l2; i++) {
		b[i] = s[l2-i-1]-48;
		res[i] = 0;
	}
	lmax = max(l1,l2);
	res[lmax+1] = 0;
	for(int i = min(l1,l2)+1; i <= lmax; i++) {
		if (i > l1) a[i] = 0;
		if (i > l2) b[i] = 0;
	}

	for(int i = 0; i < lmax; i++) {
		int r = a[i]+b[i];
		res[i] += r;
		for(int j = i+1; j <= lmax; j++) {
			res[j] += res[j-1] / 10;
			res[j-1] %= 10;
		}
	}
	if (res[lmax+1]) lmax++;

	for(int i = lmax; i >= 0; i--)
		out << res[i];

	out.close();
	return 0;
}