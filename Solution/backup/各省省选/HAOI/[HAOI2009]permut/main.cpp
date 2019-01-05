//[HAOI2009]逆序对数列
//dp方程：f[i][j] = ∑f[i-1][k], j-i+1<= k <=j
#include <iostream>
using namespace std;
const int MAX = 2005;
const int MOD = 10000;

int f[MAX][MAX];
int n, k;

int main()
{
    //input
    cin >>n >>k;
    //init
    for(int i=0; i<=n; ++i)
        f[i][0] = 1;
    //work(dp)
    for(int i=2; i<=n; ++i)
        for(int j=1; j<=k; ++j)
        {
            for(int m = max(0, j-i+1); m<=j; ++m)
                f[i][j] += f[i-1][m];
            f[i][j] %= MOD;
        }
    //output
    cout <<f[n][k];
    return 0;
}
