#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <list>
#include <complex>
#include <cctype>
using namespace std;

struct Entry { // Запись в телефонной книге.
	string name;
	int number;
};

int main() {

	string str1 = "Zhenya Shlykov";
	cout << str1 << '\n';

	string str2 = str1.substr(7, 7); // str2 = "Zhenya";
	cout << str2 << '\n';

	str1.replace(0, 6, "Eugene"); // str1 = "Eugene Shlykov";
	cout << str1 << '\n';

	string str3;
	getline(cin, str3); // Считать строку целиком.
	cout << str3;

	vector<Entry> books1(1000); // vector из 1000  элеентов.

	list<Entry> books2; // Список.
	// const Entry& e, list<Entry>::iterator i, list<Entry>::iterator p
	// books2.push_front(e);
	// books2.push_back(e);
	// books2.insert(i, e);
	// books2.erase(p);

	/* * *
	Стандартные контейнеры.
	vector<T>, list<T>, queue<T>, stack<T>, deque<T>, priotity_queue<T>, set<T>, multiset<T>, map<T>, multimap<T>
	* * */

	// bool operator== (const Entry& a, const Entry& b) { return a.name == b.name; };
	// unique_copy(books1.begin(), books1.end(), books2.begin()); // Записать в books2 уникальные элементы books1.
	// unique_copy(books1.begin(), books1.end(), back_inserter(books2)); // Дописать в конец books2 уникальные элементы books1.

	// Стр. 106.

	return 0;
};