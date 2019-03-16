#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int a[3], b[3];

	for(int i = 0; i < 3; i++)
		in >> a[i];
	for(int i = 0; i < 3; i++)
		in >> b[i];

	bool f;
	do {
		f = 1;
		for(int i = 0; i < 2; i++)
			if (a[i] > a[i+1]) {
				int t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				f = 0;
			}
		for(int i = 0; i < 2; i++)
			if (b[i] > b[i+1]) {
				int t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
				f = 0;
			}
	} while(!f);

	if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) out << "Boxes are equal";
		else {
			int t[3];
			for(int i = 0; i < 3; i++) {
				if (a[i] - b[i] > 0) t[i] = 1;
					else if (a[i] - b[i] < 0) t[i] = -1;
					else t[i] = 0;
			}
			if (t[0] >= 0 && t[1] >= 0 && t[2] >= 0) out << "The first box is larger than the second one";
				else if (t[0] <= 0 && t[1] <= 0 && t[2] <= 0) out << "The first box is smaller than the second one";
				else out << "Boxes are incomparable";
		}

	in.close();
	out.close();
	return 0;
}