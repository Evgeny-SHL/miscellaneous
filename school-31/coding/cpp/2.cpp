#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	freopen("lawn.in", "r", stdin);
	freopen("lawn.out", "w", stdout);
	long long x1, y1, x2, y2, x3, y3, r, ans;
	double r2;
	scanf("%I64d %I64d %I64d %I64d\n", &x1, &y1, &x2, &y2);
	scanf("%I64d %I64d %I64d\n", &x3, &y3, &r);
	if (x2 < x1) {
		int v = x2;
		x2 = x1;
		x1 = v;
	}
	if (y2 < y1) {
		int v = y2;
		y2 = y1;
		y1 = v;
	}
	r2 = r * r;
	ans = 0;
	for (long long x = max(x1, x3 - r); x <= min(x2, x3 + r); ++x) {
		long long y_up = min(y2, y3 + (long long)sqrt(r2 - (x - x3) * (x - x3)));
		long long y_down = max(y1, y3 - (long long)sqrt(r2 - (x - x3) * (x - x3)));
		ans += max((long long)0, y_up - y_down + 1);
	}
	printf("%I64d\n", ans);
	return 0;
}