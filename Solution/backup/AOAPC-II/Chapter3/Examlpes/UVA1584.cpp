#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 85;
char mark[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //work
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", mark);
        int point = 0;
        int ans = 0;
        int len = strlen(mark);
        for(int i = 0; i < len; ++i)
        {
            if(mark[i] == 'X')
                point = 0;
            else
                ans += ++point;
        }
        printf("%d\n", ans);
    }
    //return
    return 0;
}
