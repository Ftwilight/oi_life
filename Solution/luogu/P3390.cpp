#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 105;
const long long MOD = 1e9 + 7;

long long n, k;
long long base[MAX][MAX], ans[MAX][MAX];

inline void mul(long long a[MAX][MAX], long long b[MAX][MAX])
{
    long long temp[MAX][MAX];
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                (temp[i][j] += a[i][k] * b[k][j]) %= MOD;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            a[i][j] = temp[i][j];
}

inline void fast()
{
    for(int i = 0; i < n; ++i)
        ans[i][i] = 1;
    while(k)
    {
        if(k & 1)
            mul(ans, base);
        k >>= 1;
        mul(base, base);
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);

    cin >>n >>k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> base[i][j];
    fast();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout <<ans[i][j] <<" ";
        cout <<"\n";
    } 
    return 0;
}
       
