#include <iostream>
using namespace std;

const int MAX_H_SIZE = 10000+10;
const long long INF = 1000000000;
int heap[MAX_H_SIZE];
int archeap[MAX_H_SIZE];
int h_size = 0;

long long arr[MAX_H_SIZE];

void swap(long long &a, long long &b) {
	long long t = a;
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

long long best() {
	return arr[heap[1]];
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
	long long n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> arr[i];
	}
/*	for (int i = 0; i < k; ++i)
		cout << arr[i];
	cout << endl;
*/	build(k);
	cout << best() << '\n';
	for (long long i = k; i < n; ++i) {
		arr[0] = -INF;
		ch(0);
		ext();
		for (int j = 0; j < k - 1; ++j)
			arr[j] = arr[j+1];
		cin >> arr[k-1];
	/*	for (int j = 0; j < k; ++j)
			ch(j);
	*/	build(k);
	/*	cout << endl;
		for (int j = 0; j < k; ++j)
			cout << arr[j];
		cout << endl;
		for (int j = 1; j <= k; ++j)
			cout << heap[j];
		cout << endl;
	*/	cout << best() << '\n';
	}
}