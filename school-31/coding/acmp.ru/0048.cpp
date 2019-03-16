#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");


	int i = 0, sum = 0, s[5002];
	char c;
	while (!in.eof()) {
		in >> c;
		if (!in.eof()) s[i] = c-48;
		sum += s[i];
		i++;
	}
	i--;
	int n = i;
	do {
		i--;
	}	while(!s[i] && i);
	int k = n-i-1;

	out << 1;
	for(int j = 1; j <= k; j++)
		out << 0;

	in.close();
	out.close();
	return 0;
}