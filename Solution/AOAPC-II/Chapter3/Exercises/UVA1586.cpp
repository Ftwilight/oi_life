#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 25;

int num[10];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    scanf("%d", &n);
    //work
    int top;
    while(n--)
    {
        memset(num, 0, sizeof(num));
        scanf("%d", &top);
        for(int i = 1; i <= top; ++i)
        {
            int now = i;
            while(now)
            {
                ++num[now % 10];
                now /= 10;
            }
        }
        for(int i = 0; i < 10; ++i)
            if(i != 9)
                printf("%d ", num[i]);
            else
                printf("%d", num[i]);
        printf("\n");
    }
    //end
    return 0;
}
