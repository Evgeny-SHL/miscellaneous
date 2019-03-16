#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
	s.insert(1);
	s.insert(0);
	s.insert(2);
	s.insert(3);
	s.insert(4);

	set<int>* it;
	set<int>::iterator *p;
	int v = 2;
	p = &(s.begin());
	cout << p << '\n';
	p += v;
	cout << p << '\n';
	it = *p;
	cout << *it;

	return 0;
}