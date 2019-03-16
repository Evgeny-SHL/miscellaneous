#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int w, h, n;
	in >> w >> h >> n;
	char f[100][100];
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			f[i][j] = 1;

	for(int k = 1; k <= n; k++) {
		int x1, y1, x2, y2;
		in >> x1 >> y1 >> x2 >> y2;
		for(int i = y1; i < y2; i++)
			for(int j = x1; j < x2; j++)
				f[i][j] = 0;
	}

	int s = 0;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			s += f[i][j];

	out << s;

	in.close();
	out.close();

	return 0;
}
