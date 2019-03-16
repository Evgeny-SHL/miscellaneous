#include <iostream>
#include <vector>
using namespace std;

struct ans {
    int _max, _ind, left, right;
    ans(int a = 0, int b = 0, int c = 0, int d = 0) {
        _max = a;
        _ind = b;
        left = c;
        right = b;
    }
};

vector<int> mas;
vector<ans> data;

ans a_max(ans a, ans b) {
    if (a._max >= b._max)
        return a;
    return b;
}

void build(int l, int r, int v) {
    if (l == r)
        data[v] = ans(mas[l], l, l, r);
    else {
        build(l, (l + r) / 2, 2 * v);
        build((l + r) / 2 + 1, r, 2 * v + 1);
        data[v] = a_max(data[2 * v], data[2 * v + 1]);
        data[v].left = l;
        data[v].right = r;
    }
}

ans find_max(int l, int r, int v) {
    ans t1, t2;
    bool f1 = false, f2 = false;

    if (data[v].left == l && data[v].right == r) {
        return data[v];
    }
    if (l <= min(r, data[2 * v].right)) {
        f1 = true;
        t1 = find_max(l, min(r, data[2 * v].right), 2 * v);
    }
    if (max(l, data[2 * v + 1].left) <= r) {
        f2 = true;
        t2 = find_max(max(l, data[2 * v + 1].left), r, 2 * v + 1);
    }
    if (f1 && f2)
        return a_max(t1, t2);
    else if (f1)
        return t1;
    return t2;
}

int main() {
    int n, k, l, r, m, ind;

    cin >> n;
    mas.resize(n);
    data.resize(4 * n + 10);
    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
    }
    build(0, n - 1, 1);

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> l >> r;
        ans p = find_max(l - 1, r - 1, 1);
        cout << p._max << " " << p._ind + 1 << '\n';
    }

    return 0;
}