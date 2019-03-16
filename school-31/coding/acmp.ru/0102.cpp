#include <fstream>
#include <stdlib.h>
using namespace std;



int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int x1,y1,x2,y2,x3,y3,x4,y4;
	in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	double s1,s2,s3,s4;
	s4 = 0.5*abs((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3));
	s1 = 0.5*abs((x1-x4)*(y2-y4) - (x2-x4)*(y1-y4));
	s2 = 0.5*abs((x2-x4)*(y3-y4) - (x3-x4)*(y2-y4));
	s3 = 0.5*abs((x3-x4)*(y1-y4) - (x1-x4)*(y3-y4));

	bool f = s4 == s1+s2+s3;
	if (f) out << "In";
		else out << "Out";

	in.close();
	out.close();
	return 0;
}