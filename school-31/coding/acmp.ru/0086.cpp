#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;
	out << n*n-3*(n-1)-1;

	in.close();
	out.close();
	return 0;
}