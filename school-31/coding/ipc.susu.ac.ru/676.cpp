#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	long long a, b;
	long long layer1, layer2;
	long long min1, min2, max1, max2;
	long long mid1, mid2;
	long long left1, left2;
	long long right1, right2;
	long long x1, y1;
	long long x2, y2;

	cin >> a >> b;

	layer1 = ceil((1.0 + sqrt(2.0 * a - 1.0)) / 2.0);
	layer2 = ceil((1.0 + sqrt(2.0 * b - 1.0)) / 2.0);

	if (layer1 == 1) {
		min1 = 1;
	} else {
		min1 = 2 * (layer1 - 1) * (layer1 - 2) + 2;
	}
	if (layer2 == 1) {
		min2 = 1;
	} else {
		min2 = 2 * (layer2 - 1) * (layer2 - 2) + 2;
	}
	max1 = 2 * layer1 * (layer1 - 1) + 1;
	max2 = 2 * layer2 * (layer2 - 1) + 1;

	mid1 = (min1 + max1 + 1) / 2;
	mid2 = (min2 + max2 + 1) / 2;

	left1 = (min1 + mid1) / 2;
	left2 = (min2 + mid2) / 2;

    right1 = mid1 * 2 - left1;
    right2 = mid2 * 2 - left2;

    if (layer1 == 1) {
		x1 = 0;
		y1 = 0;
    } else {
		if (min1 <= a && a < left1) {
			x1 = -(a - min1);
			y1 = (a - left1);
		} else if (left1 <= a && a < mid1) {
			x1 = (a - mid1);
			y1 = (a - left1);
		} else if (mid1 <= a && a < right1) {
			x1 = (a - mid1);
			y1 = -(a - right1);
		} else {
			x1 = -(a - max1 - 1);
			y1 = -(a - right1);
		}
    }

	if (layer2 == 1) {
		x2 = 0;
		y2 = 0;
    } else {
		if (min2 <= b && b < left2) {
			x2 = -(b - min2);
			y2 = (b - left2);
		} else if (left2 <= b && b < mid2) {
			x2 = (b - mid2);
			y2 = (b - left2);
		} else if (mid2 <= b && b < right2) {
			x2 = (b - mid2);
			y2 = -(b - right2);
		} else {
			x2 = -(b - max2 - 1);
			y2 = -(b - right2);
		}
    }

    cout << abs(x1 - x2) + abs(y1 - y2) << "\n";

	return 0;
}