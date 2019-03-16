#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	string num;
//	getline(in, num);
	getline(cin, num);

	cout << num.length();

	int k = num.length();
	int l = 0;
	while (k > 1) {
		int sum = 0;
		++l;
		for (int i = 0; i < k; ++i) {
			sum += (num[i] - '0');
		}
		num = sum;
	}


	return 0;
}