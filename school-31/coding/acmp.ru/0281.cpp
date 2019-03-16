#include <fstream>
using namespace std;

long int res(int n,int m);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m;
	in >> n >> m;
	out << res(n,m);

	in.close();
	out.close();
	return 0;
}

long int s = 0, k = 0;

long int res(int n,int m) {
	if (n >= 1) {
		for(int i = 0; i <= 1; i++) {
			res(n-1, m);
			s += i;
		}
		if (s >= m) k++;
	}
	return k;
}