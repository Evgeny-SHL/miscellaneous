#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct animal {
	bool s;
	long long w;
	animal(bool a = false, long long b = 0) {
		s = a;
		w = b;
	}
};

bool comp(animal x, animal y) {
	return x.w < y.w;
}

ifstream cin("learning.in");
ofstream cout("learning.out");

vector<animal> cow;
vector< pair<int, int> > sgm;

int main() {

	int n;
	long long a, b, w1, w2;
	long long k = 0;
	string str;

	cin >> n >> a >> b;

	cow.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> str >> cow[i].w;
		cow[i].s = (str == "S");
	}

	sort(cow.begin(), cow.end(), comp);

	if (cow[0].s) {
		sgm.push_back(make_pair(1, cow[0].w));
	}

	for (int i = 1; i < n; ++i) {
		if (cow[i].s && cow[i - 1].s) {
			w1 = cow[i - 1].w;
			w2 = cow[i].w;
			if (sgm.size() > 0 && sgm[sgm.size() - 1].second == w1) {
				++w1;
			}
			sgm.push_back(make_pair(w1, w2));
		} else if (cow[i - 1].s) {
			w1 = cow[i - 1].w;
			w2 = (w1 + cow[i].w) / 2;
			if (sgm.size() > 0 && sgm[sgm.size() - 1].second == w1) {
				++w1;
			}
			sgm.push_back(make_pair(w1, w2));
		} else if (cow[i].s) {
			w2 = cow[i].w;
			w1 = (cow[i - 1].w + w2 + 1) / 2;
			if (sgm.size() > 0 && sgm[sgm.size() - 1].second == w1) {
				++w1;
			}
			sgm.push_back(make_pair(w1, w2));
		}
	}

	if (cow[n - 1].s) {
		if (sgm.size() > 0 && sgm[sgm.size() - 1].second == cow[n - 1].w) {
				sgm.push_back(make_pair(cow[n - 1].w + 1, 1000000000));
		} else {
			sgm.push_back(make_pair(cow[n - 1].w, 1000000000));
		}
	}

	for (int i = 0; i < sgm.size(); ++i) {
		w1 = sgm[i].first;
		w2 = sgm[i].second;
	//	cout << w1 << " " << w2 << '\n';
		if (w2 < a || w1 > b) {
			continue;
		}
		if (w1 >= a && w2 <= b) {
			k += w2 - w1 + 1;
		} else if (w1 >= a) {
			k += b - w1 + 1;
		} else if (w2 <= b) {
			k += w2 - a + 1;
		}
	}

	cout << k << '\n';

	return 0;
}