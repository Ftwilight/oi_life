#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

typedef long long ll;

const int MAX = 1e6+5;
const int INF = 0x3f3f3f3f;

bool not_prime[MAX];

void excel(ll l, ll r)
{
    memset(not_prime, 0, sizeof(not_prime));
    ll top = sqrt(r);
    for(ll i = 2; i <= top; ++i)
        for(ll j = std::max(l/i, i); i*j <= r; ++j)
            if(i * j >= l && i * j <= r)
                not_prime[i * j - l] = true;
}

int main()
{
    //freopen("data.in", "r", stdin);
    ll l, r;
    while(scanf("%lld %lld", &l, &r) == 2)
    {
        if(l == 1)
            ++l;
        excel(l, r);
        ll max_dif = 0, max_l = 0, max_r = 0;
        ll min_dif = INF, min_l = 0, min_r = 0;
        ll last = -1;
        bool have_ans = false;
        for(ll i = l; i <= r; ++i)
        {
            ll me = i - l;
            if(!not_prime[me])
            {
                //printf("[%d]\n", i);
                if(last != -1)
                {
                    ll diff = me - last;
                    if(diff > max_dif)
                    {
                        max_dif = diff;
                        max_l = last + l;
                        max_r = i;
                    }
                    if(diff < min_dif)
                    {
                        min_dif = diff;
                        min_l = last + l;
                        min_r = i;
                    }
                    have_ans = true;
                }
                last = me;
            }
        }
        if(have_ans)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", min_l, min_r, max_l, max_r);
        else
            printf("There are no adjacent primes.\n");
    }
    return 0;
}
