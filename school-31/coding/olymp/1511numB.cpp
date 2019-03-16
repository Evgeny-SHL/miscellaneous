#include <bits/stdc++.h>
#define int1 long long
using namespace std;

int main()
{
	int1 k, n, m, a, b;
	cin >> a >> n >> b >> m >> k;
	if (m > n)
	{
		swap(a, b);
		swap(m, n);
		if (k == 1)
		{
			cout << (a + b) % 10;
			return 0;
		}
		if (k <= m)
		{
			cout << (a + b + 1) % 10;
			return 0;
		}
		if (k <= n)
		{
			cout << (a + (a / 10));
			return 0;
		}
		if ((a == 9) && (k == n + 1))
		{
			cout << 1;
			return 0;
		}
	}
	
}
