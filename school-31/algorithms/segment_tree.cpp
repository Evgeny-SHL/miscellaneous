#include <iostream>
#include <vector>
using namespace std;

struct node {
	int key;
	int ind;
	int left;
	int right;
	node(int a = 0, int b = 0, int c = 0, int d = 0) {
		key = a;
		ind = b;
		left = c;
		right = d;
	}
};

vector<int> arr;
vector<node> data;

node n_max(node a, node b) {
	if (a.key >= b.key)
        return a;
    return b;
}

void build(int l, int r, int v) {
    if (l == r)
        data[v] = node(arr[l], l, l, r);
    else {
        build(l, (l + r) / 2, 2 * v);
        build((l + r) / 2 + 1, r, 2 * v + 1);
        data[v] = n_max(data[2 * v], data[2 * v + 1]);
        data[v].left = l;
        data[v].right = r;
    }
}

node find_max(int l, int r, int v) {
    node t1, t2;
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
        return n_max(t1, t2);
    else if (f1)
        return t1;
    return t2;
}

int main() {
	int n, m, l, r;

	cin >> n;
	arr.resize(n);
	data.resize(4 * n + 1);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> m;

	build(0, n - 1, 1);
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		node c = find_max(l - 1, r - 1, 1);
		cout << c.key << " " << c.ind + 1 << '\n';
	}

	return 0;
}