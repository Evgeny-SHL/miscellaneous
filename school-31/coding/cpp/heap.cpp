#include <iostream>
using namespace std;

const int MAX_H_SIZE = 500;
int heap[MAX_H_SIZE+1];
int h_size = 0;

int arr[100] = {5, 13, 2, 25, 7, 17, 20, 8, 1, 4};

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int comp(int a, int b) {
	return arr[a] < arr[b];
}

int h_comp(int a, int b) {
	return comp(heap[a], heap[b]);
}

void exch(int a, int b) {
	swap(heap[a], heap[b]);
}

void up_main(int ind) {
	while ((ind > 1) && h_comp(ind, ind / 2)) {
		exch(ind, ind / 2);
		ind /= 2;
	}
}

void down_main(int ind) {
    int i;
	while ((i=2*ind) <= h_size) {
		if (i < h_size && h_comp(i+1, i)) i++;
		if (!h_comp(i, ind)) break;
        exch(i, ind);
        ind = i;
	//	cout << ind << '\n';
	}
}

int ext() {
	exch(1, h_size--);
	down_main(1);
	return heap[h_size+1];
}

void ins(int index) {
	heap[++h_size] = index;
	up_main(h_size);
}

void build(int amount) {
	for (int i = 1; i <= amount; i++)
		heap[i] = i-1;
	h_size = amount;
	for (int i = h_size / 2; i >= 1; i--) {
		down_main(i);
	}
}

int main() {
	build(8);
	ins(9);
	while (h_size > 0)
		cout << arr[ext()] << '\n';
	return 0;
}
