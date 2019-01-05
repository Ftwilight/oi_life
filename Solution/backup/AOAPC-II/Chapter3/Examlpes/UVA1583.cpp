#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 100005;

int list[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //excel
    int cnt = 0;
    while(++cnt)
    {
        int sum = cnt;
        int num = cnt;
        while(num)
        {
            sum += num % 10;
            num /= 10;
        }
        if(sum < MAX && !list[sum])
            list[sum] = cnt;
        if(sum >= MAX)
            break;
    }
    //work
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", list[t]);
    }
    //return
    return 0;
}
