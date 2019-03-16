#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("packing.in");
ofstream fout("packing.out");

int main() {
    int l1, w1, h1, l2, w2, h2, lc, wc, hc;

    fin >> l1 >> w1 >> h1;
    fin >> l2 >> w2 >> h2;
    fin >> lc >> wc >> hc;

    if (h1 > hc || h2 > hc) {
        fout << "NO";
    } else {
        if (l1 + l2 <= lc && max(w1, w2) <= wc ||
            l1 + l2 <= wc && max(w1, w2) <= lc ||
            l1 + w2 <= lc && max(w1, l2) <= wc ||
            l1 + w2 <= wc && max(w1, l2) <= lc ||
            max(l1, l2) <= lc && w1 + w2 <= wc ||
            max(l1, l2) <= wc && w1 + w2 <= lc ||
            max(l1, w2) <= lc && w1 + l2 <= wc ||
            max(l1, w2) <= wc && w1 + l2 <= lc ||
            l1 + l2 <= wc && max(w1, w2) <= lc ||
            l1 + l2 <= lc && max(w1, w2) <= wc ||
            l1 + w2 <= wc && max(w1, l2) <= lc ||
            l1 + w2 <= lc && max(w1, l2) <= wc ||
            max(l1, l2) <= wc && w1 + w2 <= lc ||
            max(l1, l2) <= lc && w1 + w2 <= wc ||
            max(l1, w2) <= wc && w1 + l2 <= lc ||
            max(l1, w2) <= lc && w1 + l2 <= wc) {
            fout << "YES";
        } else {
            if (h1 + h2 <= hc &&
                (max(l1, l2) <= lc && max(w1, w2) <= wc ||
                max(l1, l2) <= wc && max(w1, w2) <= lc ||
                max(l1, w2) <= lc && max(w1, l2) <= wc ||
                max(l1, w2) <= wc && max(w1, l2) <= lc)) {
                fout << "YES";
            } else {
                fout << "NO";
            }
        }
    }
    fout << '\n';

    return 0;
}
