/*
ID: ugnthes1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

	int N;
	int num[7];

	for (int i = 0; i < 7; ++i)
		num[i] = 0;

	fin >> N;
	num[5] = 1;
	int k = 5;
	for (int month = 1; month <  12 * N; ++month) {
		int l = (month - 1) % 12;
		int year = 1900 + month / 12;
		if (l == 0 || l == 2 || l == 4 || l == 6 || l == 7 || l == 9 || l == 11) k += 31;
		else if (l == 3 || l == 5 || l == 8 || l == 10) k += 30;
		else if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) k += 29;
		else k += 28;
		k = k % 7;
		++num[k];
	}

	fout << num[5] << " " << num[6] << " " << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << " " << num[4] << endl;


    return 0;
}