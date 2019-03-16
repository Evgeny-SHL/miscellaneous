#define _ijps 1
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

#define name ""
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

struct __isoff{
	__isoff(){
		//if (_ijps)
		//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
		//else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
		ios_base::sync_with_stdio(0);
		srand(time(0));
	}
	~__isoff(){
		//if(_ijps) cerr<<times<<'\n';
	}
} __osafwf;
const ull p1 = 131797;
const ull p2 = 435493969;
const double eps = 1e-7;
const double pi = acos(-1.0);

const ll inf = 1e18 + 7;
const ll infi = 1e9 + 7;
const ll dd = 1e6 + 7;
const ll mod = 1e9 + 7;

int main(){
	double t;
	int ws = 1;
	while(1){
		ws++;
		string a1, a2;
		system("gen.exe");

		ifstream f1("output.txt");
		system("bfs.exe");
		f1 >> a1;

		ifstream f2("output2.txt");
		system("gg.exe");
		f2 >> a2;

		cerr << a1 << ' ' << a2 << '\n';
		if(a1 != a2){
			cout << a1 << ' ' << a2;
			break;
		}
	}

}