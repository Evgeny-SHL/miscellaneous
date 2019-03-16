#include <fstream>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int x1, y1, x2, y2, x3, y3, x4, y4;
	in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int dx1 = x2-x1, dy1 = y2-y1, dx2 = x4-x3, dy2 = y4-y3;
	double x, y;
	bool f = 0;

	if (dy1 && dx1*dy2 - dx2*dy1) {
		y = (double) (y1*dx1*dy2 + x3*dy1*dy2 - x1*dy1*dy2 - y3*dy1*dx2) / (dx1*dy2 - dx2*dy1);
		x = (double) (y*dx1 + x1*dy1 - y1*dx1) / dy1;
		f = (x >= min(x1,x2) && x <= max(x1,x2) && y >= min(y1,y2) && y <= max(y1,y2) && x >= min(x3,x4) && x <= max(x3,x4) && y >= min(y3,y4) && y <= max (y3,y4));
	} else if ((dy1 && dy2 && (double)dx1/dy1==(double)dx2/dy2) || (dx1 && dx2 && (double)dy1/dx1==(double)dy2/dx2) || (dx1==dx2 && !dy1 && !dy2) || (!dx1 && !dx2 && dy1==dy2)) {
		f = abs(dx1)+abs(dx2) > abs(max(max(x1,x2),max(x3,x4))-min(min(x1,x2),min(x3,x4))) &&
		abs(dy1)+abs(dy2) > abs(max(max(y1,y2),max(y3,y4))-min(min(y1,y2),min(y3,y4)));
	}	else if (!dy1 && dy2) {
		y = (double) y1;
		x = (double) (y*dx2 + x3*dy2 - y3*dx2) / dy2;
		f = (x >= min(x1,x2) && x <= max(x1,x2) && y >= min(y1,y2) && y <= max(y1,y2) && x >= min(x3,x4) && x <= max(x3,x4) && y >= min(y3,y4) && y <= max (y3,y4));
	}

	if (f) out << "Yes";
		else out << "No";

	in.close();
	out.close();
	return 0;
}