#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int m[100000];

	long int i = 0;
	while (!in.eof()) {
		in >> m[i];
		i++;
	}
	long int n = i;

	bool f;
	do {
		f = 1;
		for(long int i = 0; i < n-1; i++)
			if (m[i]>m[i+1]) {
				f = 0;
				int t = m[i];
				m[i] = m[i+1];
				m[i+1] = t;
			}
	}	while (!f);

	f = 1;
	i = 1;
	long int d = m[1] - m[0];
	do {
		if (m[i+1] - m[i] != d) f = 0;
		i++;
	}	while ((f) && (i < n-1));

	if (f) out << "Yes";
	else out << "No";

	in.close();
	out.close();

	return 0;
}