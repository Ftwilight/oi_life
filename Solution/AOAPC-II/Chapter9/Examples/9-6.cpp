#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1050;

struct Lamp
{
    int v, k, c, l;
    Lamp():v(0), k(0), c(0), l(0)
    {}
    bool operator<(const Lamp &other) const
    {
        return v < other.v;
    }
};

Lamp l[MAX];
int s[MAX];
int f[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d %d %d %d", &l[i].v, &l[i].k, &l[i].c, &l[i].l);
        //work
        sort(l+1, l+n+1);
        for(int i = 1; i <= n; ++i)
            s[i] = s[i-1] + l[i].l;
        for(int i = 1; i <= n; ++i)
        {
            f[i] = INF;
            for(int j = 0; j < i; ++j)
                f[i] = min(f[i], f[j]+ l[i].k + (s[i]-s[j])*l[i].c);
        }
        //output
        printf("%d\n", f[n]);
    }
    //end
    return 0;
} 
