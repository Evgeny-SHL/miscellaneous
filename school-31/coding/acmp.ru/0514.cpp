#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	 long int k;
	 in >> k;
	 out << floor((-1 + sqrt((double) 1 + 8*k))/2);

	in.close();
	out.close();
	return 0;
}