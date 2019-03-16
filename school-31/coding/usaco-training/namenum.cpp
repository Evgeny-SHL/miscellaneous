/*
ID: ugnthes1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");
    ofstream fout ("namenum.out");

	long long num;
	char but[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
	'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

	fin >> num;

	int l = 0;
	set<char> let[12];
	while (num > 0) {
		int d = num % 10;

		switch(d) {
			case 2:
				let[l].insert(but, but + 3);
				break;
			case 3:
				let[l].insert(but + 3, but + 6);
				break;
			case 4:
				let[l].insert(but + 6, but + 9);
				break;
			case 5:
				let[l].insert(but + 9, but + 12);
				break;
			case 6:
				let[l].insert(but + 12, but + 15);
				break;
			case 7:
				let[l].insert(but + 15, but + 18);
				break;
			case 8:
				let[l].insert(but + 18, but + 21);
				break;
			case 9:
				let[l].insert(but + 21, but + 24);
				break;
		}

		num /= 10;
		++l;
	}

	bool finded = false;
	int n = 4617; // Длина словаря.
	for (int i = 0; i < n; ++i) {
		string name;
		dict >> name;
		if (name.length() != l) continue;
		bool stop = false;
		for (int j = 0; !stop && j < l; ++j)
			if (let[l-j-1].find(name[j]) == let[l-j-1].end()) stop = true;
		if (stop) continue;
		finded = true;
		fout << name << endl;
	}

	if (!finded) fout << "NONE" << endl;

    return 0;
}