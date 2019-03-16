#include <iostream>
#include <vector>
using namespace std;
// heap, heap_sort, prioriry_queue

vector<int> a;
vector<int> heap;
int heap_size;
const int ERR = -1;
const int INF = 1e9 + 7;

int parent(int i) {
	return i / 2;
}

int left(int i) {
	return 2 * i;
}

int right(int i) {
	return 2 * i + 1;
}

int heap_minimum() {
	return heap[1];
}

void min_heapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest;
	if (l <= heap_size && heap[l] < heap[i])
		smallest = l;
	else smallest = i;
	if (r <= heap_size && heap[r] < heap[smallest])
		smallest = r;
	if (smallest != i) {
		int v = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = v;
		min_heapify(smallest);
	}
}

void build_min_heap() {
	heap_size = a.size();
	heap.resize(heap_size + 1);
	for (int i = 1; i <= a.size(); ++i)
		heap[i] = a[i - 1];
	for (int i = heap_size / 2; i >= 1; --i)
		min_heapify(i);
}

void heap_sort() {
	build_min_heap();
	for (int i = heap_size; i >= 2; --i) {
		int v = heap[1];
		heap[1] = heap[i];
		heap[i] = v;
		--heap_size;
		min_heapify(1);
	}
}

int heap_extract_min() {
	if (heap_size < 1)
		return ERR;
	int m = heap[1];
	heap[1] = heap[heap_size];
	--heap_size;
	min_heapify(1);
	return m;
}

void heap_decrease_key(int i, int key) {
	if (key > heap[i])
		return;
	heap[i] = key;
	while (i > 1 && heap[parent(i)] > heap[i]) {
		int v = heap[i];
		heap[i] = heap[parent(i)];
		heap[parent(i)] = v;
		i = parent(i);
	}
}

void min_heap_insert(int key) {
	++heap_size;
	heap[heap_size] = INF;
	heap_decrease_key(heap_size, key);
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	heap_sort();

	for (int i = 1; i <= n; ++i)
		cout << heap[i] << " ";
	cout << '\n';

	return 0;
}