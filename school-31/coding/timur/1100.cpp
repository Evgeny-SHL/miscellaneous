#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > score;

int main() {

	int n;
	cin >> n;

	score.resize(110);

	int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		score[y].push_back(x);
	}

	for (int i = 100; i >= 0; --i)
		for (int j = 0; j < score[i].size(); ++j)
			cout << score[i][j] << " " << i << '\n';

	return 0;
}