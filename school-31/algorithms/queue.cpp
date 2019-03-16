#include <iostream>
#include <vector>
using namespace std;

vector<int> q;
const int ERR = -1;
int head;
int tail;

void enqueue(int x) {
	q[tail] = x;
	if (tail == q.size() - 1)
		tail = 1;
	else ++tail;
}

int dequeue() {
	int x = q[head];
	if (head == q.size() - 1)
		head = 1;
	else ++head;
	return x;
}

int main() {
	int n, k, l, x;

	cin >> n >> k;
	q.resize(n + 1);
	head = 1;
	tail = 1;
	for (int i = 0; i < k; ++i) {
		cin >> l;
		if (l == 1) {
			cin >> x;
			enqueue(x);
		} else
			cout << dequeue() << '\n';
		if (tail > head)
			for (int i = head; i < tail; ++i)
				cout << q[i] << " ";
		else if (tail < head) {
			for (int i = head; i <= n; ++i)
				cout << q[i] << " ";
			for (int i = 1; i < tail; ++i)
				cout << q[i] << " ";
		}
		cout << '\n';
	}


	return 0;
}