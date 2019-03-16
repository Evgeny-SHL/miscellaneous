#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int a, b;
	in >> a >> b;
	switch (a % 10) {
		case 0:
			out << 0;
			break;
		case 1:
			out << 1;
			break;
		case 2:
			switch (b % 4) {
				case 0:
					out << 6;
					break;
				case 1:
					out << 2;
					break;
				case 2:
					out << 4;
					break;
				case 3:
					out << 8;
					break;
			}
			break;
		case 3:
			switch (b % 4) {
				case 0:
					out << 1;
					break;
				case 1:
					out << 3;
					break;
				case 2:
					out << 9;
					break;
				case 3:
					out << 7;
					break;
			}
			break;
		case 4:
			switch (b % 2) {
				case 0:
					out << 6;
					break;
				case 1:
					out << 4;
					break;
			}
			break;
		case 5:
			out << 5;
			break;
		case 6:
			out << 6;
			break;
		case 7:
			switch (b % 4) {
				case 0:
					out << 1;
					break;
				case 1:
					out << 7;
					break;
				case 2:
					out << 9;
					break;
				case 3:
					out << 3;
					break;
			}
			break;
		case 8:
			switch (b % 4) {
				case 0:
					out << 6;
					break;
				case 1:
					out << 8;
					break;
				case 2:
					out << 4;
					break;
				case 3:
					out << 2;
					break;
			}
			break;
		case 9:
			switch (b % 2) {
				case 0:
					out << 1;
					break;
				case 1:
					out << 9;
					break;
			}
			break;
	}

	in.close();
	out.close();
	return 0;
}