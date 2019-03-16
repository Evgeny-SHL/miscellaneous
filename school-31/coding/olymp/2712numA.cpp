#include <iostream>
#include <vector>
using namespace std;

vector< vector< vector< bool > > > p;
vector<int> a, b, a1, b1;

int main() {
    int k, h = 0, m = 0, n = 0;
    cin >> k;
    a.resize(k + 1);
    b.resize(k + 1);
    a1.resize(k + 1);
    b1.resize(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        a1[i] = a[i];
        h = max(h, a[i]);
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
        b1[i] = b[i];
    }
    p.resize(h + 2);
    for (int s = 0; s <= h + 1; ++s) {
        p[s].resize(k + 1);
        for (int i = 0; i <= k; ++i) {
            p[s][i].resize(k + 1);
        }
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            p[0][i][j] = true;
        }
    }
    for (int s = 1; s <= h; ++s) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (!p[s - 1][i][j]) {
                    continue;
                }
                if (a[i] >= s && b[k - j + 1] >= s) {
                    p[s][i][j] = true;
                    ++m;
                }
            }
        }
    }/*
    for (int s = 1; s <= h; ++s) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                cout << p[s][i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }*/

    for (int s = 0; s <= h; ++s) {
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                p[s][i][j] = false;
            }
        }
    }

    for (int s = h; s >= 1; --s) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (p[s + 1][i][j]) {
                    p[s][i][j] = true;
                    ++n;
                    if (a[i] >= s) {
                        --a[i];
                    }
                    if (b[j] >= s) {
                        --b[j];
                    }
                }
            }
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (!p[s][i][j] && a[i] >= s && b[j] >= s) {
                    p[s][i][j] = true;
                    ++n;
                    --a[i];
                    --b[j];
                }
            }
        }
     //   for (int i = 1; i <= k; ++i) {
     //       cout << a[i] << " ";
     ////   }
     //   cout << '\n';
     ////   for (int i = 1; i <= k; ++i) {
     //       cout << b[i] << " ";
    //    }
    //    cout << '\n';
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (!p[s][i][j] && (a[i] >= s) || (b[j] >= s)) {
                 //   cout << a[i] << " " << b[j] << '\n';
                    if (a1[i] >= s && b1[j] >= s) {
                     //   cout << i << " " << j << '\n';
                        p[s][i][j] = true;
                        ++n;
                        if (a[i] >= s) {
                            --a[i];
                        } else if (b[j] >= s) {
                            --b[j];
                        }
                    }
                }
            }
        }
    }

  /*   for (int s = 1; s <= h; ++s) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                cout << p[s][i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }*/
    cout << n << " " << m << '\n';

    return 0;
}
