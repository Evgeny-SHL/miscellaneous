#define INPUT 1
#define OUTPUT 0
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define PII pair<int, int>
#define PLL pair<ll, ll >
#define VI vector<int>
#define VVI vector<VI>
#define dbg(x) cerr << #x << " = " << (x) << endl;

const double PI = acos(-1);
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const ll INFL = 8e18 + 7;

#ifdef LOCAL
	bool debug = 1;
#else
	bool debug = 0;
#endif

void run();

int main()
{
	#ifdef LOCAL
		if (INPUT)
			freopen("input.txt", "r", stdin);
		if (OUTPUT)
			freopen("output.txt", "w", stdout);
		if (!DEBUG)
			debug = 0;
		int st = clock();
	#endif

	run();

	#ifdef LOCAL
		int en = clock();
		freopen("CON", "w", stdout);
		printf("%.3f seconds \n", (en - st) / (double) CLOCKS_PER_SEC);
	#endif

	return 0;
}

const int N = 1e5 + 7;
int t, n1, n2;

const int AMN = 3;
const ll MODS[AMN] = {1000000003, 1000000007, 1000000009};
const ll CONSTS[AMN] = {13, 17, 19};
ll KS[AMN][N];
ll hs1[AMN][N], hs2[AMN][N];

string s1;

bool check()
{
	bool ok = 0;
	for (int i = 1; i <= n1; i++)
	{
		ok = 1;
		for (int h = 0; h < AMN; h++)
		{
			ll h1 = (hs1[h][n1] - hs1[h][i - 1] + MODS[h]) % MODS[h];
			h1 = (h1 + hs1[h][i - 1] * KS[h][n1]) % MODS[h];
			ll h2 = hs2[h][n2] * KS[h][i - 1] % MODS[h];
			ok &= h1 == h2;
		}
		if (ok)
			break;
	}
	return ok;
}

void run()
{
	scanf("%d", &t);

	for (int h = 0; h < AMN; h++)
		KS[h][0] = 1;
	for (int h = 0; h < AMN; h++)
		for (int i = 1; i < N; i++)
			KS[h][i] = KS[h][i - 1] * CONSTS[h] % MODS[h];

	while (t--)
	{
		string s2;
		cin >> s1 >> s2;
		n1 = (int) s1.length();
		n2 = (int) s2.length();
		s1 = " " + s1;
		s2 = " " + s2;

		for (int h = 0; h < AMN; h++)
		{
			for (int i = 1; i <= n1; i++)
				hs1[h][i] = (hs1[h][i - 1] + (s1[i] - 'a') * KS[h][i]) % MODS[h];
			for (int i = 1; i <= n2; i++)
				hs2[h][i] = (hs2[h][i - 1] + (s2[i] - 'a') * KS[h][i]) % MODS[h];
		}

		bool ok = check();

		reverse(s1.begin() + 1, s1.end());
		for (int h = 0; h < AMN; h++)
			for (int i = 1; i <= n1; i++)
				hs1[h][i] = (hs1[h][i - 1] + (s1[i] - 'a') * KS[h][i]) % MODS[h];

		ok |= check();
		ok &= (s1.size() == s2.size());
		printf("%s\n", ok ? "YES" : "NO");
	}
}
/*
if (debug) printf(": %d \n", );
if (debug) printf("\n");
*/