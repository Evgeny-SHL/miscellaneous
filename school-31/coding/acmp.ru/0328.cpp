#include <fstream>
using namespace std;

bool prime(int n);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	long long int s = 0;
	in >> n;
	for(int i = 0; i <= n; i++)
		for(int j = i; j <= n; j++)
			s += i+j;
	out << s;


	in.close();
	out.close();
	return 0;
}