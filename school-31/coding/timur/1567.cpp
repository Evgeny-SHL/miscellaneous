#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	getline(cin, str);

	int sum = 0;
	for (int i = 0; i < str.length(); ++i) {
		switch(str[i]) {
			case 'a':
			case 'd':
			case 'g':
			case 'j':
			case 'm':
			case 'p':
			case 's':
			case 'v':
			case 'y':
			case '.':
			case ' ':
				sum += 1;
				break;
			case 'b':
			case 'e':
			case 'h':
			case 'k':
			case 'n':
			case 'q':
			case 't':
			case 'w':
			case 'z':
			case ',':
				sum += 2;
				break;
			case 'c':
			case 'f':
			case 'i':
			case 'l':
			case 'o':
			case 'r':
			case 'u':
			case 'x':
			case '!':
				sum += 3;
		}
	}

	cout << sum;

	return 0;
}