#include <iostream>
#include <string>
using namespace std;

int main() {

	string place;
	cin >> place;

	char let;
	int num;

	let = place[place.length() - 1];
	num = place[place.length() - 2] - '0';
	if (place.length() > 2) num += 10 * (place[0] - '0');

	if (let == 'A') cout << "window";
	else {
		if (num < 3 && let == 'D') cout << "window";
		else if (num < 3) cout << "aisle";
		else if (num < 21 && let == 'F') cout << "window";
		else if (num < 21) cout << "aisle";
		else if (let == 'K') cout << "window";
		else if (let == 'C' || let == 'D' || let == 'G' || let == 'H') cout << "aisle";
		else cout << "neither";
	}

	return 0;
}