#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

ifstream fin("Results.txt");
ofstream t_fout("Territories.txt");
ofstream s_fout("Schools.txt");
ofstream p_fout("Participants.txt");
ofstream r_fout("Answer.txt");
ofstream fout("Wrong.txt");

struct Result {
	int ID, pID, tID, sID;
	int form, year;
	vector<int> pt;
	Result(int a, int b, int c, int d, int e, int f, vector<int> g) {
		ID = a;
		pID = b;
		tID = c;
		sID = d;
		form = e;
		year = f;
		pt = g;
	}
};

map<string, int> part;
map<int, string> get_part;
map<string, int> terr;
map<int, string> get_terr;
map<int, map<string, int> > school;
map<int, pair<int, string> > get_school;
vector<Result> res;

int main() {
	string str;
	int n, m, k, l;

	string snm;
	string nam;
	string ptr;
	string fll;
	string trr;
	string sch;
	int yr;
	int fr;
	vector<int> pnts;

	string s;

	n = 0;
	m = 0;
	k = 0;
	l = 0;


	int cnt = 0;
	string prv = "";
	while (!fin.eof()) {
		getline(fin, str);
		++cnt;
		snm = "";
		int i = 0;
		while (str[i] != '\t' && str[i] != ' ') {
			snm += str[i];
			++i;
		}
		do {
			++i;
		} while (str[i] == ' ' || str[i] == '\t');
		nam = "";
		while (str[i] != '\t' && str[i] != ' ') {
			nam += str[i];
			++i;
		}
		do {
			++i;
		} while (str[i] == ' ' || str[i] == '\t');
		ptr = "";
		while (str[i] != '\t' && str[i] != ' ') {
			ptr += str[i];
			++i;
		}
		do {
			++i;
		} while (str[i] == ' ' || str[i] == '\t');
		fll = snm + "\t" + nam + "\t" + ptr;
		if (cnt < 10) {
			fout << fll << "\n";
			if (prv == fll) {
				fout << "OK\n";
			} else {
				fout << "NO\n";
			}
			fout << prv << "\n" << fll << "\n";
			for (int i = 0; i < prv.length(); ++i) {
				fout << (int)prv[i] << " " << (int)fll[i] << " ";
				fout << (prv[i] == fll[i]) << "\n";
			}
			fout << "\n";
			fout << prv.length() << " " << fll.length() << "\n";
			prv = fll;
		}
		if (part.find(fll) == part.end()) {
			++m;
			part[fll] = m;
			get_part[m] = fll;
		}

		trr = "";
		while (str[i] != '\t') {
			trr += str[i];
			++i;
		}
		do {
			++i;
		} while (str[i] == '\t' || str[i] == ' ');
		if (terr.find(trr) == terr.end()) {
			++k;
			terr[trr] = k;
			get_terr[k] = trr;
		}

		sch = "";
		while (str[i] != '\t') {
			sch += str[i];
			++i;
		}
		do {
			++i;
		} while (str[i] == '\t' || str[i] == ' ');
		if (school.find(terr[trr]) == school.end()) {
			++l;
			school[terr[trr]][sch] = l;
			get_school[l] = make_pair(terr[trr], sch);
		} else {
			if (school[terr[trr]].find(sch) == school[terr[trr]].end()) {
				++l;
				school[terr[trr]][sch] = l;
				get_school[l] = make_pair(terr[trr], sch);
			}
		}

		fr = 0;
		while (str[i] != ' ' && str[i] != '\t') {
			fr = 10 * fr + (str[i] - '0');
			++i;
		}

		do {
			++i;
		} while (str[i] == '\t' || str[i] == ' ');

		yr = 0;

		while (str[i] != ' ' && str[i] != '\t') {
			yr = 10 * yr + (str[i] - '0');
			++i;
		}

		do {
			++i;
		} while (str[i] == '\t' || str[i] == ' ');

		pnts.resize(8);
		for (int t = 0; t < 8; ++t) {
			pnts[t] = 0;
			while (i < str.length() && str[i] != ' ' && str[i] != '\t') {
				pnts[t] = 10 * pnts[t] + (str[i] - '0');
				++i;
			}
			do {
				++i;
			} while (i < str.length() && str[i] == '\t' || str[i] == ' ');
		}

		res.push_back(Result(++n, part[fll],
		terr[trr],
		school[terr[trr]][sch],
		fr, yr, pnts));

	}

	for (auto it = get_part.begin(); it != get_part.end(); ++it) {
		p_fout << it->first << "\t" << it->second << "\n";
	}
	for (auto it = get_terr.begin(); it != get_terr.end(); ++it) {
		t_fout << it->first << "\t" << it->second << "\n";
	}
	for (auto it = get_school.begin(); it != get_school.end(); ++it) {
		s_fout << it->first << "\t" << (it->second).second << "\t" << (it->second).first << "\n";
	}

	for (int i = 0; i < res.size(); ++i) {
		r_fout << res[i].ID << "\t";
		r_fout << res[i].pID << "\t";
		r_fout << res[i].tID << "\t";
		r_fout << res[i].sID << "\t";
		r_fout << res[i].form << "\t";
		r_fout << res[i].year << "\t";
		for (int t = 0; t < 7; ++t) {
			r_fout << res[i].pt[t] << "\t";
		}
		r_fout << res[i].pt[7] << "\n";
	}


	return 0;
}