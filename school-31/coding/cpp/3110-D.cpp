#include <iostream>
#include <vector>
using namespace std;

struct ans {
	int len, st;
	ans(int a = 0, int b = 0) {
		len = a;
		st = b;
	}
};

vector<int> s;
vector<int> cum;

ans get_answer(int n) {
	ans mn = ans(0, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = n; j >= i; --j)
			if(cum[j] - cum[i - 1] == 0 && (j - i + 1) > mn.len)
				mn =  ans(j - i + 1, i);
	return mn;
}

int main() {
	int n;

	cin >> n;
	s.resize(n + 1, 0);
	cum.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		cum[i] = s[i] + cum[i - 1];
	}

	ans a = get_answer(n);

	cout << a.len << " " << a.st;

	return 0;
}