#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct detail
{
    long long a, b;
    long long ta, tb;

    detail(long long a, long long b) :
        a(a), b(b)
    {}

    void flip()
    {
        swap(a, b);
        swap(ta, tb);
    }
};

ostream& operator<<(ostream& out, const detail& d)
{
    return out << "<" << d.a << ", " << d.b << ">";
}

long long make(vector<detail*>& d)
{
    size_t n = d.size();
    detail* worst = d[0];
    for (size_t i = 1; i < n; i++)
    {
        if (min(d[i]->a, d[i]->b) > min(worst->a, worst->b))
            worst = d[i];
    }
    bool flipped = false;
    if (worst->b > worst->a)
    {
        flipped = true;
        for (size_t i = 0; i < n; i++)
            d[i]->flip();
    }
    vector<detail*> A, B;
    for (size_t i = 0; i < n; i++)
    {
        if (d[i] == worst)
            continue;
        if (d[i]->a < d[i]->b)
            A.push_back(d[i]);
        else
            B.push_back(d[i]);
    }
    long long ta(0);
    long long tb(0);
    worst->ta = ta;
    ta += worst->a;
    for (size_t i = 0; i < B.size(); i++)
    {
        B[i]->tb = tb;
        tb += B[i]->b;
        B[i]->ta = ta;
        ta += B[i]->a;
    }
    for (size_t i = 0; i < A.size(); i++)
    {
        A[i]->tb = tb;
        tb += A[i]->b;
        ta = max(ta, tb);
        A[i]->ta = ta;
        ta += A[i]->a;
    }
    tb = max(worst->a, tb);
    worst->tb = tb;
    tb += worst->b;
    if (flipped)
        for (size_t i = 0; i < n; i++)
            d[i]->flip();
    return max(ta, tb);
}

int main()
{
    ifstream in("o2cmax.in");
    ofstream out("o2cmax.out");
    size_t n;
    in >> n;
    assert (0 < n && n <= 200000);
    vector<detail*> d(n);
    {
        vector<int> a(n);
        for (size_t i = 0; i < n; i++)
        {
            in >> a[i];
            assert (0 <= a[i] && a[i] <= 1000000000);
        }
        vector<int> b(n);
        for (size_t i = 0; i < n; i++)
        {
            in >> b[i];
            assert (0 <= b[i] && b[i] <= 1000000000);
        }
        for (size_t i = 0; i < n; i++)
            d[i] = new detail(a[i], b[i]);
    }
    long long ans = make(d);
    out << ans << "\n";
    for (size_t i = 0; i < n; i++)
        out << d[i]->ta << " ";
    out << "\n";
    for (size_t i = 0; i < n; i++)
        out << d[i]->tb << " ";
    out << "\n";
}
