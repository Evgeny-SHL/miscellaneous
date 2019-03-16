#include <fstream>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	char c;
	unsigned int s1 = 0, s2 = 0, i = 1;
	while(!in.eof()) {
		in >> c;
		if (!in.eof()) {
		int t = c - 48;
		if (i % 2) s1 += t;
			else {
				s2 += t;
				i = 0;
			}
		i++;
		}
	}

	if (!(abs(s1-s2) % 11)) out << "YES";
		else out << "NO";

	in.close();
	out.close();
	return 0;
}