//洛谷数据加强版
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 22;
long long n, m, x, y;
long long f[MAX][MAX];

bool judge(int i, int j)
{
    return !(((abs(i - x) + abs(j - y) == 3) && abs(i - x) && abs(j - y)) || (i == x && j == y));
}

int main()
{
    //file
    freopen("pj024.in", "r", stdin);
    freopen("pj024.out", "w", stdout);
    //input
    cin >>n >>m >>x >>y;
    //init
    f[0][0] = 1;
    for(int i = 0; i <= n && judge(i, 0); ++i)
        f[i][0] = 1;
    for(int i = 0; i <= m && judge(0, i); ++i)
        f[0][i] = 1;
    //work
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(judge(i, j))
                f[i][j] = f[i-1][j] + f[i][j-1];
    //output
    cout <<f[n][m] <<"\n";
    return 0;
}

