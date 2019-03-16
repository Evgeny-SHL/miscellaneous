/*
ID: agaky21
LANG: C++
TASK: contact
*/

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("contact.in");
ofstream fout("contact.out");

struct s_seq {
	string s;
	long long cnt;
	s_seq(string p1 = "", long long p2 = 0) {
		s = p1;
		cnt = p2;
	}
};

bool comp (s_seq a, s_seq b) {
	return (a.cnt > b.cnt ||
		a.cnt == b.cnt && a.s.length() < b.s.length() ||
		a.cnt == b.cnt && a.s.length() == b.s.length() && a.s < b.s);
}

map<string, long long> cnt;
vector<s_seq> v;

int main() {
	int a, b, n, m, k, u;
	string seq, s1;

	fin >> a >> b >> n;

	seq = "";
	while (fin >> s1) {
		seq += s1;
	}

	m = seq.length();
	for (int l = a; l <= b; ++l) {
		for (int i = 0; i < m - l + 1; ++i) {
			s1 = "";
			for (int j = i; j < i + l; ++j) {
				s1 += seq[j];
			}
			if (cnt.find(s1) != cnt.end()) {
				++cnt[s1];
			} else {
				cnt[s1] = 1;
			}
		}
	}

	for (map<string, long long>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
		v.push_back(s_seq((*it).first, (*it).second));
	}

	sort(v.begin(), v.end(), comp);

	k = 0;
	u = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (k == 0 ||  v[i].cnt != v[i - 1].cnt) {
			++k;
			u = 0;
			if (k > n) {
				break;
			}
			if (k > 1) {
				fout << '\n';
			}
			fout << v[i].cnt << '\n';
			fout << v[i].s;
			u = 1;
		} else {
			if (u == 6) {
				fout << '\n' << v[i].s;
				u = 1;
			} else {
				fout << " " << v[i].s;
				++u;
			}
		}
	}
	fout<<"\n";

	return 0;
}
