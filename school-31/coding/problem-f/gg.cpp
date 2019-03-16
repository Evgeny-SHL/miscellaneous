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
		if (_ijps)
			freopen("input.txt", "r", stdin), freopen("output2.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
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
const ll dd = 2e5 + 7;
const ll mod = 1e9 + 7;

struct eg{
	int to, mF, F, q;
	eg(int _t, int _mf, int f, int Q):to(_t), mF(_mf), F(f), q(Q){ }
};

vector<vector<eg> > P;

void addeg(int a, int b){
	P[a].push_back(eg(b, 1, 0, P[b].size()));
	P[b].push_back(eg(a, 0, 0, P[a].size() - 1));
}

int T[dd], ti = 1, t;

bool dfs(int v){
	if(T[v] == ti)
		return 0;
	if(v == t)
		return 1;
	T[v] = ti;
	for(int i = 0; i < P[v].size(); i++){
		if(P[v][i].F != P[v][i].mF)
			if(dfs(P[v][i].to)){
				P[P[v][i].to][P[v][i].q].F -= 1;
				P[v][i].F += 1;
				return 1;
			}
	}
	return 0;
}


bool gg;

void magec(int v){
	ti++;
	if(!dfs(v))
		gg = 0;
}

vector<pair<int, int> > ER;


int main(){
	int n, m, s;
	cin >> n >> m;
	P.resize(n * 3);
	forn(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ER.push_back(mk(a, b));
	}
	forn(i, n){
		forn(j, i){
			s = i, t = j;
			P.clear();
			P.resize(n * 3);
			forn(i, n){
				if (i != s && i != t)
					addeg(i, i + n);
			}
			P[s].push_back(eg(s + n, 10, 0, P[s + n].size()));
			P[s + n].push_back(eg(s, 0, 0, P[s].size() - 1));

			P[t].push_back(eg(t + n, 10, 0, P[t + n].size()));
			P[t + n].push_back(eg(t, 0, 0, P[t].size() - 1));

			forn(q, m){
				addeg(ER[q].first + n, ER[q].second);
				addeg(ER[q].second + n, ER[q].first);
			}

			gg = 1;
			magec(s + n);
			magec(s + n);
			magec(s + n);
			if (gg){
				vector<int> A, B, C;
				int q = s + n;
				A.push_back(q - n);
				while (q != t){
					for (i = 0; i < P[q].size(); i++)
						if (P[q][i].F == 1){
							P[q][i].F = 0;
							q = P[q][i].to;
							if(q < n)
								A.push_back(q);
						}
				}

				q = s + n;
				B.push_back(q - n);
				while (q != t){
					for (i = 0; i < P[q].size(); i++)
					if (P[q][i].F == 1){
						P[q][i].F = 0;
						q = P[q][i].to;
						if(q < n)
							B.push_back(q);
					}
				}

				q = s + n;
				C.push_back(q - n);
				while (q != t){
					for (i = 0; i < P[q].size(); i++)
					if (P[q][i].F == 1){
						P[q][i].F = 0;
						q = P[q][i].to;
						if(q < n)
							C.push_back(q);
					}
				}
				set<int> S;
				bool fl = 1;
				forn(w, A.size()){
					if(!(A[w] == s || A[w] == t))
						S.insert(A[w]);
				}
				forn(w, B.size()){
					if(!(B[w] == s || B[w] == t)){
						if(S.count(B[w]))
							fl = 0;
						S.insert(B[w]);
					}
				}
				forn(w, C.size()){
					if(!(C[w] == s || C[w] == t)){
						if(S.count(C[w]))
							fl = 0;
						S.insert(C[w]);
					}
				}
				//if(fl){
					cout << "YES";
					return 0;
				//}

			}
		}
	}
	cout << "NO";
}