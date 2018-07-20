#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        long long remain = 0;
        long long ans = 0;
        //work
        for(int i = 0; i < n; ++i)
        {
            long long t;
            scanf("%lld", &t);
            remain += t;
            ans += abs(remain);
        }
        //output
        printf("%lld\n", ans);
    }
    //end
    return 0;
    
} 
