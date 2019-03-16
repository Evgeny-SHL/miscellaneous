#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int m[5][2] = { {0, 0}, {25, 0}, {50, 0}, {75, 0}, {100, 0} }, t[5] = { 0, 0, 0, 0, 0}, x, y, k = 0;
	for(int i = 1; i <= 5; i++) {
		in >> x >> y;
		for(int j = 0; j < 5; j++)
			if (pow(x-m[j][0], 2) + pow(y-m[j][1], 2) <= 100) t[j] = 1;
	}
	for(int j = 0; j < 5; j++)
		if (t[j]) k++;
	out << k;

	in.close();
	out.close();
	return 0;
}