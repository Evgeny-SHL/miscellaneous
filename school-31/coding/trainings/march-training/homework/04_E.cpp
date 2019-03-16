#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

struct node {
	node *left, *right;
	int key, size, value;
	long long prior;
	node (int param1, int param2) {
		key = param1;
		value = param2;
		prior = rand() * rand();
		left = right = nullptr;
		size = 1;
	}
};

int get_size(node *v) {
	return v == nullptr ? 0 : v->size;
}

void update(node *v) {
	if (v != nullptr) {
		v->size = get_size(v->left) + get_size(v->right) + 1;
	}
}

void print(node *root) {
	if (root != nullptr) {
		print(root->left);
		cout << root->value << " ";
		print(root->right);
	}
}

void split(node *root, node* &left, node* &right, int key) {
	if (root == nullptr) {
		left = right = nullptr;
	} else {
		int root_key = get_size(root->left);
		if (root_key < key) {
			split(root->right, root->right, right, key - root_key - 1);
			left = root;
		} else {
			split(root->left, left, root->left, key);
			right = root;
		}
		update(root);
	}
}

void merge(node* &root, node *left, node *right) {
	if (left == nullptr || right == nullptr) {
		root = ((right == nullptr) ? left : right);
	} else {
		if (left->prior > right->prior) {
			merge(left->right, left->right, right);
			update(left);
			root = left;
		} else {
			merge(right->left, left, right->left);
			update(right);
			root = right;
		}
	}
}

void insert(node* &root, int key, int value) {
	node *left = nullptr;
	node *right = nullptr;
	split(root, left, right, key);
	merge(left, left, new node(key, value));
	merge(root, left, right);
}

void erase(node* &root, int key) {
	node *left = nullptr;
	node *middle = nullptr;
	node *right = nullptr;
	split(root, left, middle, key);
	split(middle, middle, right, 1);
	merge(middle, middle->left, middle->right);
	merge(root, left, middle);
	merge(root, root, right);
}

node *Root = nullptr;
vector<int> a;

void init(int n) {
	Root = nullptr;
	for (int i = 0; i < n; ++i) {
		insert(Root, i, a[i]);
	}
}

int main() {
	freopen("kthmax.in", "r", stdin);
	freopen("kthmax.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, k, v;

	for (int i = 1; i <= n; ++i) {
		cin >> k >> v;
		if (k == 1) {
			insert(Root, i, v);
		} else if (k == -1) {
			erase(Root, v);
		} else {
			cout << kth(Root, v) << "\n";
		}
	}

	return 0;
}
