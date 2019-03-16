#include <cmath>

class QuadraticLaw {
public:
    long long getTime (long long d) {
        long long t = floor(sqrt(0.25 + d) - 0.5);
        long long ans = t;
        int k = 7;
        if (t >= k)
            for (long long p = t - k; p < t + k + 1; ++p) {
                if ((d - p - p * p >= 0) && (d - p - p * p < d - ans - ans * ans)) ans = p;
            }
        return ans;
    }
};
