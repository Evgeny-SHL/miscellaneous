#include <iostream>
#include <fstream>
using namespace std;

void hanoi(int n, char a, char b, char c);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int m;
	while (!in.eof()) {
		in >> m;
		out << m << " ";
	}

	in.close();
	out.close();

	return 0;
}