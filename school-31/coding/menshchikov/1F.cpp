#include <fstream>
#include <algorithm>
using namespace std;

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int cards[5];
	for (int i = 0; i < 5; i++)
		in >> cards[i];

	sort(cards, cards + 5);
	int a, b, c, d, e;
	a = cards[0];
	b = cards[1];
	c = cards[2];
	d = cards[3];
	e = cards[4];

	if ((a == b) && (b == c) && (c == d) && (d == e)) out << "Impossible";
	else if ((a == b) && (b == c) && (c == d) || (b == c) && (c == d) && (d == e)) out << "Four of a Kind";
	else if ((a == b) && (b == c) && (d == e) || (a == b) && (c == d) && (d == e)) out << "Full House";
	else if ((e == d + 1) && (d == c + 1) && (c == b + 1) && (b == a + 1)) out << "Straight";
	else if ((a == b) && (a == c) || (b == c) && (c == d) || (c == d) && (d == e)) out << "Three of a Kind";
	else if ((a == b) && (c == d) || (a == b) && (d == e) || (b == c) && (d == e)) out << "Two Pairs";
	else if ((a == b) || (b == c) || (c == d) || (d == e)) out << "One Pair";
	else out << "Nothing";

	return 0;
}