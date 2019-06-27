#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <cassert>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	long long l, w, r;
	cin >> l >> w >> r;
	long long g = gcd(w, r);
	if (w + r - l > g) {
		cout << "DEADLOCK" << endl;
	}
	else {
		cout << "OK" << endl;
	}
	return 0;
}