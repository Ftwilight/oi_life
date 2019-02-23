#include <cstdio>
#include <cmath>
#include <iostream>

const int MAX = 1e4+1;
const int INF = 1e6;

int busket[INF+1];

int main()
{
    // freopen("data.in", "r", stdin);
    int n, t, ans=0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &t);
        ans = std::max(ans, t);
        int sq = sqrt(t);
        for(int i = 1; i <= sq; ++i)
            if(!(t % i))
            {
                ++busket[i];
                if(i * i != t)
                    ++busket[t / i];
            }
    }
    for(int i = 1; i <= n; ++i)
    {
        while(busket[ans] < i)
            --ans;
        printf("%d\n", ans);
    }
    return 0;
}
