#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ifstream in("words.txt");
	ofstream out("base.txt");

	char s[5];
	s="папа";
	while(!in.eof()) {
		for(int i=0; i<4; i++) in >> s[i];
		cout << s;
		for(int i=0; i<4; i++) {
			if (s[i]=' ') out << 'а';
			else if (s[i]='-') out << '-';
			else out << s[i];
			out << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}