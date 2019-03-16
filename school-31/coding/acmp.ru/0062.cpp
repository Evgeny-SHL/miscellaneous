#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	char s[3];
	in >> s;
	int l = s[0]-64, n = s[1]-48;
	if ((l+n) % 2) out << "WHITE";
		else out << "BLACK";

	in.close();
	out.close();
	return 0;
}