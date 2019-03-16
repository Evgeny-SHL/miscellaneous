#include <iostream>
#include <vector>
using namespace std;

vector<int> s;
const int ERR = -1;
int top;

bool stack_empty() {
	if (top == 0)
		return true;
	else return false;
}

void push(int x) {
	++top;
	s[top] = x;
}

int pop() {
	if (stack_empty())
		return ERR;
	else {
		--top;
		return s[top + 1];
	}
}

int main() {
	int n, k, l, x;

	cin >> n >> k;
	s.resize(n);
	top = 0;
	for (int i = 0; i < k; ++i) {
		cin >> l;
		if (l == 1) {
			cin >> x;
			push(x);
		} else
			cout << pop() << '\n';
		for (int i = 1; i <= top; ++i)
			cout << s[i] << " ";
		cout << '\n';
	}

	return 0;
}