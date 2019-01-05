#include <iostream>
#include <cstdio>
using namespace std;


long long n, s1, v1, s2, v2, ans;

long long enum_s1();
long long enum_s2();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    int cnt;
    scanf("%d", &cnt);
    for(int i = 1; i <= cnt; ++i)
    {
        ans = 0;
        scanf("%lld %lld %lld %lld %lld", &n, &s1, &v1, &s2, &v2);
        //work
        if(n > 2*s1*s2)
        {
            long long num = n/(s1*s2)-1;
            n -= num*(s1*s2);
            ans += num*max(s1*v2, s2*v1);
        }
        if(n/s1 < n/s2)
            ans += enum_s1();
        else
            ans += enum_s2();
        //output
        printf("Case #%d: %lld\n", i, ans);
    }
    //end
    return 0;
} 

long long enum_s1()
{
    long long val = 0;
    for(long long i = 0; i*s1 <= n; ++i)
    {
        long long all_s1 = i*v1;
        long long all_s2 = (n-i*s1)/s2*v2;
        val = max(val, all_s1+all_s2);
    }
    return val;
}

long long enum_s2()
{
    long long val = 0;
    for(long long i = 0; i*s2 <= n; ++i)
    {
        long long all_s2 = i*v2;
        long long all_s1 = (n-i*s2)/s1*v1;
        val = max(val, all_s1+all_s2);
    }
    return val;
}
