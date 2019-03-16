#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int a1, a2, n;
	long int aN;
	in >> a1 >> a2 >> n;

	aN = a1 + (a2-a1)*(n-1);
	out << aN;

	in.close();
	out.close();
	return 0;
}