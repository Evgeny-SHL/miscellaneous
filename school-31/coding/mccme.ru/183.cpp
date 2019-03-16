#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> A;

int main() {
	int N, q, w;

	fin >> N;

	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		fin >> A[i];
	}

	fin >> q >> w;

	for (int i = 1; i <= N; ++i) {
		if (i != q && A[i] == A[q]) {
			A[i] = A[w];
		}
	}
	A[q] = A[w];

	for (int i = 1; i <= N; ++i) {
		fout << A[i] << " \n"[i == N];
	}

	return 0;
}