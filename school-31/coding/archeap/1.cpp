#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

int main()
{
	int n;
	cin >> n;
	pair <int, int> dot[1001];
	for (int i = 0; i < n; i++)
		cin >> dot[i].first >> dot[i].second;
	double minc = 2;
	int z1, z2, z3;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
			{
				if (i != j && i != k && j != k) {
					double dx1 = -(dot[i].first - dot[j].first);
					double dy1 = -(dot[i].second - dot[j].second);
					double dx2 = -(dot[i].first - dot[k].first);
					double dy2 = -(dot[i].second - dot[k].second);
					double cos = (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2));
					if (cos < minc - EPS)
					{
						minc = cos;
						z1 = j + 1;
						z2 = i + 1;
						z3 = k + 1;
					}
				}
			}
	cout << z1 << ' ' << z2 << ' ' << z3;
	return 0;
}
 
