/*
ID: ugnthes1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    int NP;
    map<string, int> sum;
    string name, group, fr[10];

    fin >> NP;
    for (int i = 0; i < NP; ++i) {
    	fin >> name;
    	fr[i] = name;
    	sum[name] = 0;
    }

    for (int i = 0; i < NP; ++i) {
    	int money, NG;
    	fin >> group >> money >> NG;
    	if (NG) sum[group] += -money + (money % NG);
    	for (int j = 0; j < NG; ++j) {
    		fin >> name;
    		sum[name] += money / NG;
    	}
    }

    for (int i = 0; i < NP; ++i)
    	fout << fr[i] << " " << sum[fr[i]] << endl;

    return 0;
}