#include <fstream>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long long int a, b;
	in >> a >> b;
	while (a*b > 0) {
		if (a > b) a %= b;
			else b %= a;
	}
	out << a + b;

	in.close();
	out.close();
	return 0;
}