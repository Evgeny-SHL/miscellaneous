#include <fstream>
#include <stdlib.h>
using namespace std;



int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	long int x1, y1, x2, y2, k = 0;
	in >> x1 >> y1 >> x2 >> y2;

	out << x2-x1 << " " << y2-y1 << endl;

	if (x2-x1) {
		for(long int x = x1; x <= x2; x++)
			if (!((x-x1)%(x2-x1))) k++;
	}	else if (y2-y1) {
			for(long int y = y1; y <= y2; y++)
				if (!((y-y1)%(y2-y1))) k++;
	}	else k = 1;

	out << k;

	in.close();
	out.close();
	return 0;
}