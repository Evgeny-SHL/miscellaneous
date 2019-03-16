/*
ID: agaky21
LANG: C++
TASK: fence9
*/

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("fence9.in");
ofstream fout("fence9.out");

int main() {
	int n, m, p;
	fin >> n >> m >> p;
	int a = p + __gcd(n, m) + __gcd(abs(n - p), m);
	fout << (m * p - a) / 2 + 1 << '\n';
	return 0;
}
