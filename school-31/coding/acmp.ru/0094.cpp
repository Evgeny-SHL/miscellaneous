#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n, m, k, s;
	in >> n >> m >> k;
	s = m;


	if (m-n > 0 && m-n+k >= m) out << "NO";
		else {
			int i = 0;
			do {
				i++;
				m -= n;
				if (m <= 0) break;
				m += k;
			}	while (m>0);

			out << i;
		}

	in.close();
	out.close();
	return 0;
}