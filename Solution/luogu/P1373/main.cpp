#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 801;
const long long MOD = 1e9+7;

int f[MAX][MAX][16][2];
int a[MAX][MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n, m, k;
    cin >>n >>m >>k;
    ++k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >>a[i][j];
            f[i][j][a[i][j]][0] = 1;
        }
    //work
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int p = 0; p < k; ++p)
            {
                f[i][j][p][0] += f[i-1][j][(p-a[i][j]+k)%k][1]%MOD;
                f[i][j][p][0] += f[i][j-1][(p-a[i][j]+k)%k][1]%MOD;
                
                f[i][j][p][1] += f[i-1][j][(p+a[i][j])%k][0]%MOD;
                f[i][j][p][1] += f[i][j-1][(p+a[i][j])%k][0]%MOD;
                
                if(!p)
                {
                    ans += (long long)f[i][j][p][1];
                    ans %= MOD;
                }
            }
    //output
    cout <<ans;
    //end
    return 0;
}
