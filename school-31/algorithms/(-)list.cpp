#include <iostream>
#include <vector>
using namespace std;

const int NIL = -1;
vector<int> next;
vector<int> prev;
vector<int> key;
int head;
int nil;

int list_search(int k) {
	int x = head;
	while (x != NIL && key[x] != k)
		x = next[x];
	return x;
}

void list_insert(int x) {
	next[x] = head;
	if (head != NIL)
		prev[head] = x;
	head = x;
	prev[x] = NIL;
}

void list_delete(int x) {
	if (prev[x] != NIL)
		next[prev[x]] = next[x];
	else head = next[x];
	if (next[x] != NIL)
		prev[next[x]] = prev[x];
}

// если используются ограничители
int sentinel_list_search(int k) {
	int x = next[nil];
	while (x != nil && key[x] != k)
		x = next[x];
	return x;
}

void sentinel_list_insert(int x) {
	next[x] = next[nil];
	prev[next[nil]] = x;
	next[nil] = x;
	prev[x] = nil;
}

void sentinel_list_delete(int x) {
	next[prev[x]] = next[x];
	prev[next[x]] = prev[x];
}

int main() {


	return 0;
}