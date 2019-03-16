#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;

	in >> n;
	for(int i = 1; i <=n; i++) {
		int s1 = 0, s2 = 0, r[6];
		bool f = 0;
		for(int j = 1; j <= 6; j++) {
			char t;
			in >> t;
			r[j-1] = t-48;
			if (j <=3) s1 += r[j-1];
				else s2 += r[j-1];
		}
		if (s2>s1 && r[5]>0 || s2<s1 && r[5]<9) f = 1;
			else if (s2 > s1) {
				r[5] = 9;
				r[4]--;
				if (r[4] == -1) {
					r[4] = 9;
					r[3]--;
					if (r[3] == -1) {
						r[3] = 9;
						r[2]--;
						if (r[2] == -1) {
							r[2] = 9;
							r[1]--;
							if (r[1] == -1) {
								r[1] = 9;
								r[0]--;
							}
						}
					}
				}
				s1 = r[0]+r[1]+r[2];
				s2 = r[3]+r[4]+r[5];
				f = s1 == s2;
			}	else if (s2 < s1) {
				r[5] = 0;
				r[4]++;
				if (r[4] == 10) {
					r[4] = 0;
					r[3]++;
					if (r[3] == 10) {
						r[3] = 0;
						r[2]++;
						if (r[2] == 10) {
							r[2] = 0;
							r[1]++;
							if (r[1] == 10) {
								r[1] = 0;
								r[0]++;
							}
						}
					}
				}
				s1 = r[0]+r[1]+r[2];
				s2 = r[3]+r[4]+r[5];
				f = s1 == s2;
			}
		if (f) out << "Yes" << endl;
			else out << "No" << endl;
	}

	in.close();
	out.close();
	return 0;
}