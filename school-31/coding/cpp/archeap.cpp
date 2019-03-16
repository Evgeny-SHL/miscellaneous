#include <iostream>
using namespace std;

const int MAX_H_SIZE = 500;
int heap[MAX_H_SIZE+1];
int archeap[MAX_H_SIZE+1];
int h_size = 0;

int arr[MAX_H_SIZE] = {5, 13, 2, 25, 7, 17, 20, 8, 1, 4};

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
    swap(archeap[a], archeap[b]);
    heap[archeap[a]] = a;
    heap[archeap[b]] = b;
}

void up_main(int ind) {
	while ((ind > 1) && h_comp(ind, ind / 2)) {
		exch(heap[ind], heap[ind/2]);
		ind /= 2;
	}
}

void down_main(int ind) {
    int i;
	while ((i=2*ind) <= h_size) {
		if (i < h_size && h_comp(i+1, i)) i++;
		if (!h_comp(i, ind)) break;
        exch(heap[i], heap[ind]);
        ind = i;
	}
}

int ext() {
	exch(heap[1], heap[h_size--]);
	down_main(1);
	return heap[h_size+1];
}

void ins(int index) {
	heap[++h_size] = index;
	archeap[index] = h_size;
	up_main(h_size);
}

void build(int amount) {
	for (int i = 1; i <= amount; i++) {
		heap[i] = i-1;
		archeap[i-1] = i;
    }
	h_size = amount;
	for (int i = h_size / 2; i >= 1; i--) {
		down_main(i);
	}
}

void ch(int index) {
    up_main(archeap[index]);
    down_main(archeap[index]);
}

int main() {
	build(8);
	ins(9);
	while (h_size > 0)
		cout << arr[ext()] << '\n';
	return 0;
}
