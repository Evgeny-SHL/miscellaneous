#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

long double toG(int n, char *s);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int m[1000];
	long double m1[1000];
	char s[1000][3];
	int n;
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> m[i] >> s[i];
		m1[i] = toG(m[i],s[i]);
	}

	bool f;
	do {
		f = 1;
		for(int i = 0; i < n-1; i++)
			if (m1[i] > m1[i+1]) {
				f = 0;
				long double t = m1[i];
				m1[i] = m1[i+1];
				m1[i+1] = t;
			}
	}	while (!f);

	for(int i = 0; i < n; i++) {
		int j = -1;
		do {
			j++;
		}	while (m1[i] != toG(m[j],s[j]));
		out << m[j] << " " << s[j] << endl;
		m[j] = 0;
	}

	in.close();
	out.close();

	return 0;
}

long double toG(int n, char *s) {
	long double m = n;

	switch (s[0]) {
		case 'm':
			m /= 1000;
			break;
		case 'k':
			m *= 1000;
			break;
		case 'M':
			m *= 1000000;
			break;
		case 'G':
			m *= 1000000000;
			break;
	}

	if (!strcmp(s,"p") || !strcmp(s,"mp") || !strcmp(s,"kp") || !strcmp(s,"Mp") || !strcmp(s,"Gp")) m *= 16380;
	if (!strcmp(s,"t") || !strcmp(s,"mt") || !strcmp(s,"kt") || !strcmp(s,"Mt") || !strcmp(s,"Gt")) m *= 1000000;

	return m;
}