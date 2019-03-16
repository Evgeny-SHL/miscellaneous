#include <fstream>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, x, y, m = 0;
	in >> n;
	for(int i = 0; i <= n/5; i++)
		for(int j = 0; j <= n/3; j++){
			if (5*i+3*j == n && m == 0) {
				x = i;
				y = j;
				m = x+y;
			}
			if (5*i+3*j == n && i+j < m) {
				x = i;
				y = j;
				m = x+y;
			}
		}

	out << x << " " << y;

	in.close();
	out.close();
	return 0;
}