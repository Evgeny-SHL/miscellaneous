#include <stdio.h>
#include <vector>
using namespace std;

vector<char[101]> a, b;

int main() {
	FILE *fin, *fout;
	fin = fopen("bw.in", "r");
	fout = fopen("bw.out", "w");
	char func[5], cur[3];
	int w, h;
	fscanf(fin, "%d%d", &w, &h);
	for (int i = 0; i < h; ++i) {
		fscanf(fin, "%s", &a[i]);
	}
	for (int i = 0; i < h; ++i) {
		fscanf(fin, "%s", &b[i]);
	}
	fscanf(fin, "%s", func);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cur[0] = a[i][j];
			cur[1] = b[i][j];
			if (cur == "00") {
				fprintf(fout, "%c", func[0]);
			} else if (cur == "01") {
				fprintf(fout, "%c", func[1]);
			} else if (cur == "10") {
				fprintf(fout, "%c", func[2]);
			} else {
				fprintf(fout, "%c", func[3]);
			}
		}
		fprintf(fout, "\n");
	}
	return 0;
}