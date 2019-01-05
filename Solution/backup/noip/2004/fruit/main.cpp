#include <iostream>
#include <algorithm>
#include <cstdio>
long long g[20000];
using namespace std;

bool com(long long a, long long b)
{return a>b;}
void fix();
int n;
long long res;

int main()
{
    //freopen("fruit.in", "r", stdin);
    //freopen("fruit.out", "w", stdout);
    cin >>n;
    for(int i=1; i<=n; ++i)
        cin >>g[i];
    sort(g+1, g+n+1, com);
    while(n>1)
    {
        g[n-1] = g[n-1]+g[n];
        res += g[--n];
        fix();
    }
    cout <<res;
    return 0;
}

void fix()
{
    int index = n;
    while(g[index] > g[index-1] && index>1)
    {
        swap(g[index], g[index-1]);
        --index;
    }
}
