#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, v, k;
	double x = 0, y = 0;
	in >> n;
	for(int i = 1; i <= n; i++) {
		in >> v >> k;
		switch (v) {
			case 1:
				y += k;
				break;
			case 2:
				x += k / sqrt((double) 2);
				y += k / sqrt((double) 2);
				break;
			case 3:
				x += k;
				break;
			case 4:
				x += k / sqrt((double) 2);
				y -= k / sqrt((double) 2);
				break;
			case 5:
				y -= k;
				break;
			case 6:
				x -= k / sqrt((double) 2);
				y -= k / sqrt((double) 2);
				break;
			case 7:
				x -= k;
				break;
			case 8:
				x -= k / sqrt((double) 2);
				y += k / sqrt((double) 2);
		}
	}
	if (abs(x) < 0.0005) x = 0;
	if (abs(y) < 0.0005) y = 0;

	out << std::fixed;
	out << std::setprecision(3) << x << " " << y;

	in.close();
	out.close();
	return 0;
}