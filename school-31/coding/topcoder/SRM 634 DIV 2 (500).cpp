#include <vector>

class ShoppingSurveyDiv2 {
	public:
		int minValue(int N, vector<int> s) {

			int M = s.length();
			vector<int> c(N);
			for (int i = 0; i < N; ++i) {
				c[i] = 0;
			}

			int i = 0;
			for (int j = 0; j < M; ++j) {
				while (s[j] > 0) {
					++c[i];
					--s[j];
					i = (i + 1) % N;
				}
			}

			int K = 0;
			for (int i = 0; i < N; ++i) {
				if (c[i] == M) {
					++K;
				}
			}

			return K;
		}
};