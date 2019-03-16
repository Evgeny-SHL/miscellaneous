#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, s =0;
	in >> n;

	for(int i = 1; i <=n; i++)
		if (n % i == 0) s += i;

	out << s;

	in.close();
	out.close();
	return 0;
}