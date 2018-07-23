#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long dict[35]; 

long long f(int k, int n);
inline void excel();
inline long long lines(int k);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //init
    excel();
    //input
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i)
    {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        //work
        long long ans = f(k, b)-f(k, a-1);
        //output
        printf("Case %d: %lld\n", i, ans);
    }
    //end
    return 0;
}

long long f(int k, int n)
{
    if(n == 0)
        return 0;
    else if(k == 0)
        return 1;
    
    if(n <= lines(k-1))
        return 2*f(k-1, n);
    else
        return 2*dict[k-1]+f(k-1, n-lines(k-1));
}

inline long long lines(int k)
{
    return pow(2, k);
}

inline void excel()
{
    dict[0] = 1;
    dict[1] = 3;
    for(int i = 2; i < 35; ++i)
        dict[i] = dict[i-1]*3; 
}
