#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	
	int key[11][11];
	int n;
	cin >> n;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			if (i == n)
				key[i][j] = 1;
			else 
				key[i][j] = 0;
		}
	for (int k = 1; k <= 10; k++)
	{
		int x;
		cin >> x;
		for (int d = 1; d <= x; d++)
			key[n - d][k] = 1;
	}		
	for (int k = 1; k <= 10; k++)
	{
		int x;
		cin >> x;
		for (int d = 1; d <= x; d++)
			key[n + d][k] = 1;
	}
//	for (int i = 1; i <= 10; i++)
//	{
//		for (int j = 1; j <= 10; j++)
//			cout << key[i][j] << ' ';
//		cout << endl;
//	}
	
//	cout << "OK";
	
	string s;
	for (int i = 1; i <= 10; ++i) {
		cin >> s;
//		cout << s;
		for (int j = 1; j <= 10; ++j) {
				if (s[j - 1] == '#') {
					++key[i][j];
				}
		}
	}
	
//	cout << "OK";
	
	bool f = true;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (key[i][j] != 1) f = false;
		}
	}	
	
	if (f) cout << "YES";
	else cout << "NO";
			
	return 0;
}
 
