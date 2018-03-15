#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 35;
int active[MAX][MAX];
int f[MAX];

int main()
{
    //init
#ifndef LOCAL
    freopen("teacher.in", "r", stdin);
    freopen("teacher.out", "w", stdout);
#endif
    int m, n;
    //input
    cin >>m >>n;
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            cin >>active[i][j];
    //dp
    for(int k=1; k<=m; ++k)
        for(int v=n; v>0; --v)
            for(int i=1; i<=v; ++i)
                f[v] = max(f[v], f[v-i]+active[k][i]);
    //output
    cout <<f[n];
    return 0;
}
