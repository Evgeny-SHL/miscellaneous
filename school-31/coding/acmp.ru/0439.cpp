#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, p;
	in >> n >> p;
	double k;

	k = (double) (100-p)/(100*n) + (double) p/100;
	if (k) k = (double) 1 / k;
		else k = n;

	std::fixed;
	out << std::setprecision(10) << k;

	in.close();
	out.close();
	return 0;
}