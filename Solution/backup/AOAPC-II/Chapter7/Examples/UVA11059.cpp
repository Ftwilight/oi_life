#include <cstdio>
#include <iostream>
const int MAX = 20;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    long long num[MAX];
    int cnt = 0;
    int n;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; ++i)
            scanf("%lld", num+i);
        //work
        long long ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
            {
                long long all = 1;
                for(int k = i; k <= j; ++k)
                    all *= num[k];
                ans = std::max(ans, all);
            }
        //output
        printf("Case #%d: The maximum product is %lld.\n\n", ++cnt, ans);
    }
    //end
    return 0;
}
