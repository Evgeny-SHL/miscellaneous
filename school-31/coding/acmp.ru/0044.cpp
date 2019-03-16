#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	char e,s[6];
	int k = 0;

	in >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
	s[5] = '\0';
	if ((!strcmp(s,">>-->")) || (!strcmp(s,"<--<<"))) k++;
	while (!in.eof()) {
		in >> e;
		if (!in.eof()) {
			s[0] = s[1];
			s[1] = s[2];
			s[2] = s[3];
			s[3] = s[4];
			s[4] = e;
			if ((!strcmp(s,">>-->")) || (!strcmp(s,"<--<<"))) k++;
		}
	}

	out << k;

	in.close();
	out.close();
	return 0;
}