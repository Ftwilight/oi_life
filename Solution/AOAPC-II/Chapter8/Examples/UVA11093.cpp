#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 100001;

int cost[MAX], get[MAX];
int n;

int run(int begin);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    int T;
    scanf("%d", &T);
    for(int c = 1; c <= T; ++c)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", get+i);
        for(int i = 1; i <= n; ++i)
            scanf("%d", cost+i);
        //work
        int car = 1;
        int ok = false;
        while(1)
        {
            int end = run(car);
            if(!end)
            {
                ok = true;
                break;
            }
            else if(end < car || end == n)
                break;
            car = end + 1;
            
        }
        //output
        printf("Case %d: ", c);
        if(ok)
            printf("Possible from station %d\n", car);
        else
            printf("Not possible\n");
    }
    //end
    return 0;
}

int run(int begin)
{
    bool first = true;
    int gas = 0;
    for(int i = begin; i <= n; ++i)
    {
        if(gas < 0)
            return (i-1)? i-1: n;
        if(i == begin && !first)
            return 0;
        gas += get[i]-cost[i];
        if(i == n && first)
        {
            i = 0;
            first = false;
        }
    }
    return 0;
}

