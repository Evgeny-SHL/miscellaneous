#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > graph, ways;
vector <bool> used;
vector <int> x;
vector <int> y;
vector <int> z;
int ans = 0;

bool chack(int u, int v)
{
	return (ans >= ways[u][v]);
}

int len(int i, int j)
{
	int a = x[i] - x[j];
	int b = y[i] - y[j];
	int c = z[i] - z[j];
	int answer = (a * a + b * b + c * c);
	return answer;
}

void dfs_visit(int u, int n) 
{
	used[u] = true;
	for (int v = 0; v < n; ++v) 
	{
		if (!used[v] && chack(u, v)) 
		{
			dfs_visit(v, n);
		}
	}
}

void dfs(int n) 
{
	used.resize(n, false);
	dfs_visit(0, n);
}

bool good(int n)
{
	for (int i = 0; i < n; i++)
	    if (!used[i]) return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	int a, b, c;
	++n;
	x.resize(n, 0);
	y.resize(n, 0);
	z.resize(n, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		x[i] = a;
		y[i] = b;
		z[i] = c;
	}
	graph.resize(n);
	ways.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i].push_back(j);
			graph[j].push_back(i);
			ways[i].push_back(len(i, j));
			ways[j].push_back(len(i, j));
		}
	}
	cout << "OK!!!!";
	cout.flush(); 
	int l = 0;
	int r =  400000000;
	while ((r - l) > 1)
	{
		ans = (l + r) / 2;
		dfs(n);
		if (good(n)) { 
		
			l = ans;
		} 
		else 
		{
			r = ans - 1;
		}
	}
	cout << ans << "\n";
	
}
