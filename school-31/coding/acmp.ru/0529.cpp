#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int x1, y1, x2, y2;
	in >> x1 >> y1 >> x2 >> y2;
	out << std::fixed;
	out << std::setprecision(5) << sqrt((double) (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));


	in.close();
	out.close();
	return 0;
}