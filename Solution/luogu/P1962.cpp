#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

const ll MAX = 5;
const ll MOD = 1e9 + 7;

ll cons[2][2] = {0, 1, 1, 1};

void mul(ll a[2][2], ll b[2][2])
{
    ll temp[2][2];
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                (temp[i][j] += a[i][k] * b[k][j]) %= MOD;
    memcpy(a, temp, sizeof(temp));
}

void fast(ll p)
{
    ll ans[2][2] = {1, 0, 0, 1};
    while(p)
    {
        if(p & 1)
            mul(ans, cons);
        p >>= 1;
        mul(cons, cons);
    }
    memcpy(cons, ans, sizeof(cons));
}

int main()
{
    // freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    ll n;
    cin >>n;
    fast(n - 1);
    ll ans = cons[0][0] + cons[1][0];
    cout <<ans % MOD;
    return 0;
}
