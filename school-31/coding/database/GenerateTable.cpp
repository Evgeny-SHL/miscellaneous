#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct Participant {
	int pID;
	string fam, name, patr;
	int tID, sID;
	Participant(string a, string b, string c, int d, int e, int f) {
		fam = a;
		name = b;
		patr = c;
		tID = d;
		sID = e;
		pID = f;
	}
};

struct Terrytory {
	int tID;
	string name;
	Terrytory(string a, int b) {
		name = a;
		tID = b;
	}
};

struct School {
	int sID;
	int num;
	string name;
	int tID;
	School(int a, string b, int c, int d) {
		num = a;
		name = b;
		tID = c;
		sID = d;
	}
};

struct Points {
	int year;
	int nine, ten, elev;
	Points(int a, int b, int c, int d) {
		nine = a;
		ten = b;
		elev = c;
		year = d;
	}
};

struct Result {
	int rID;
	int sID, pID, form, year;
	vector<int> res;
	Result(int a, int b, int c, int d, vector<int> e, int f) {
		sID = a;
		pID = b;
		form = c;
		year = d;
		res = e;
		rID = f;
	}
};


ifstream Tfin("Terrytories.txt");
ifstream Sfin("Schools.txt");
ofstream Rfout("Resulr.txt");

set< pair<int, string> > schools;
set< pair<int, string> >::iterator it;

int main() {

	int tID;
	string s;

    while (!Sfin.eof()) {
		getline(Sfin, s);
		string num = "Школа № ";
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				num += s[i];
			}
		}
		if (num != "Школа № ") {
			Rfout << num << "\n";
		} else {
			Rfout << s << "\n";
		}
    }

	return 0;
}