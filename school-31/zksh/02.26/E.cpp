#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

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

int get_size(node *v)
{
	return v == nullptr ? 0 : v->size;
}

void update(node *v)
{
	if (v == nullptr) {
		return;
	}
	v->size = get_size(v->left) + get_size(v->right) + 1;
}

void print(node *root) {
	if (root == nullptr) {
		return;
	}
	print(root->left);
	cout << root->value << " ";
	print(root->right);
}

void split(node *root, node* &left, node* &right, int key) {
	if (root == nullptr) {
		left = right = nullptr;
		return;
	}
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

void merge(node* &root, node *left, node *right) {
	if (left == nullptr || right == nullptr) {
			root = right == nullptr ? left : right;
			return;
	}
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
//	print(left);
//	cout << "\n";
//	print(middle);
//	cout << "\n";
	split(middle, middle, right, 1);
//	print(middle);
//	cout << "\n";
//	print(right);
//	cout << "\n";
//	cout << "bef\n";
	merge(middle, middle->left, middle->right);
//	cout << "aft";
//	print(middle);
//	cout << "\n";
//	cout << "aftprn\n";
	merge(root, left, middle);
//	cout << "ll";
	merge(root, root, right);
//	cout << "ll";
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, m, a, ind, val;
	string s;
	cin >> n >> m;
	node *root = nullptr;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		insert(root, i, a);
	}
	for (int i = 0; i < m; ++i) {
	//	print(root);
	//	cout << "\n";
		cin >> s >> ind;
		if (s == "del") {
			erase(root, ind - 1);
		//	cout << "?\m";
		} else {
			cin >> val;
			insert(root, ind, val);
		}
	}
//	cout << "?";
	cout << get_size(root) << "\n";
	print(root);
	cout << "\n";
	return 0;
}