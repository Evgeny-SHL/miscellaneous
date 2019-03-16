#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 1001;
const int n = 2;
vector<int> f[n], d[n];

bool updMin(int &x ,int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    return false;
}

int main() {
    int w;
    char c;

    fin >> w;

    for (int i = 0; i < n; ++i) {
        f[i].resize(w, -1);
        d[i].resize(w, INF);
        for (int j = 0; j < w; ++j) {
            fin >> c;
            if (c == '.') {
                f[i][j] = 1;
            } else if (c == 'X') {
                f[i][j] = 0;
            } else {
                f[i][j] = -1;
            }
        }
    }
    
    d[0][0] = 0;
    for (int j = 0; j < w; ++j) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                //  for (int j = 0; j < w; ++j) {
                if (f[i][j] < 0) {
                    continue;
                }
                if (f[i ^ 1][j] >= 0)
                    updMin(d[i ^ 1][j], d[i][j] + f[i ^ 1][j]);
                if (j < w - 1 && f[i][j + 1] >= 0) {
                    updMin(d[i][j + 1], d[i][j] + f[i][j + 1]);
                }
            }
        }
    }

    fout << min(d[0][w - 1], d[1][w - 1]) << '\n';

    return 0;
}
