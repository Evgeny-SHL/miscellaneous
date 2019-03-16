/*
ID: ugnthes1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n;
vector<vector<char> > before(10), after(10), medium(10);

vector<vector<char> > Rotation90(vector<vector<char> > a) {
	vector<vector<char> > trans(10);
	for (int i = 0; i < n; ++i) {
		trans[i].resize(10);
		for (int j = 0; j < n; ++j)
			trans[i][j] = a[n - j - 1][i];
	}
	return trans;
}

vector<vector<char> > Rotation180(vector<vector<char> > a) {
	vector<vector<char> > trans(10);
	for (int i = 0; i < n; ++i) {
		trans[i].resize(10);
		for (int j = 0; j < n; ++j)
			trans[i][j] = a[n - i - 1][n - j - 1];
	}
	return trans;
}

vector<vector<char> > Rotation270(vector<vector<char> > a) {
	vector<vector<char> > trans(10);
	for (int i = 0; i < n; ++i){
		trans[i].resize(10);
		for (int j = 0; j < n; ++j)
			trans[i][j] = a[j][n - i - 1];
	}
	return trans;
}

vector<vector<char> > Reflection(vector<vector<char> > a) {
	vector<vector<char> > trans(10);
	for (int i = 0; i < n; ++i){
		trans[i].resize(10);
		for (int j = 0; j < n; ++j)
			trans[i][j] = a[i][n - j - 1];
	}
	return trans;
}

bool Equiv(vector<vector<char> > a, vector<vector<char> > b) {
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < a[i].size(); ++j)
			if (a[i][j] != b[i][j]) return false;
	return true;
}

int main() {
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");

	fin >> n;

	char c;
	for (int i = 0; i < n; ++i) {
		before[i].resize(10);
		for (int j = 0; j < n; ++j)
			fin >> before[i][j];
	}

	for (int i = 0; i < n; ++i) {
		after[i].resize(10);
		for (int j = 0; j < n; ++j)
			fin >> after[i][j];
	}

	if (Equiv(after, Rotation90(before))) fout << 1 << endl;
	else if (Equiv(after, Rotation180(before))) fout << 2 << endl;
	else if (Equiv(after, Rotation270(before))) fout << 3 << endl;
	else if (Equiv(after, Reflection(before))) fout << 4 << endl;
	else {
		medium = Reflection(before);
		if (Equiv(after, Rotation90(medium)) ||
			Equiv(after, Rotation180(medium)) ||
			Equiv(after, Rotation270(medium))) fout << 5 << endl;
		else if (Equiv(after, before)) fout << 6 << endl;
		else fout << 7 << endl;
	}

	medium = Reflection(before);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << medium[i][j];
		cout << endl;
	}

    return 0;
}