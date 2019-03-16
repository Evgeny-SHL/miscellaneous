/*
ID: ugnthes1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");

    string comet, group;
    fin >> comet >> group;

    int a = 1, b = 1;
    for (int i = 0; i < comet.length(); ++i)
    	a *= comet[i] - 'A' + 1;
	for (int i = 0; i < group.length(); ++i)
    	b *= group[i] - 'A' + 1;

	if (a % 47 == b % 47) fout << "GO" << endl;
	else fout << "STAY" << endl;

    return 0;
}