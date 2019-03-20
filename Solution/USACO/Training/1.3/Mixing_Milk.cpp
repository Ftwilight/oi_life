#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAX = 5000 + 5;

struct Farmer
{
    int p, a;
    bool operator<(const Farmer &other) const
    {
        return p < other.p;
    }
};

Farmer f[MAX];

int main()
{
    // freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i)
        scanf("%d %d", &f[i].p, &f[i].a);
    std::sort(f, f+m);
    int cost = 0;
    for(int i = 0; i < m; ++i)
    {
        if(n >= f[i].a)
        {
            n -= f[i].a;
            cost += f[i].a * f[i].p;
        }
        else
        {
            cost += f[i].p * n;
            break;
        }
    }
    printf("%d", cost);
    return 0;
}
