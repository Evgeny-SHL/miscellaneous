#include <iostream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

map<string, int> peng;

int main() {

	int n;
	string p;
	cin >> n;
	getline(cin, p);
	peng["Emperor Penguin"] = 0;
	peng["Little Penguin"] = 0;
	peng["Macaroni Penguin"] = 0;

	for (int i = 0; i < n; ++i) {
		getline(cin, p);
		++peng[p];
	}

	int a = peng["Emperor Penguin"];
	int b = peng["Little Penguin"];
	int c = peng["Macaroni Penguin"];
	if (a > b && a > c) cout << "Emperor Penguin";
	else if (b > c) cout << "Little Penguin";
	else cout << "Macaroni Penguin";

	return 0;
}