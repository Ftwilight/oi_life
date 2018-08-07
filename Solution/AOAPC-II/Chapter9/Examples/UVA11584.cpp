#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1050;

char buf[MAX];
int dp[MAX];

bool check(int a, int b);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", buf);
        //work
        int len = strlen(buf);
        for(int i = 0; i < len; ++i)
        {
            dp[i] = i+1;
            for(int j = 0; j <= i; ++j)
                if(j == i && check(0, i))
                    dp[i] = 1;
                else if(check(j+1, i))
                    dp[i] = min(dp[i], dp[j]+1);
        }
        //output
        printf("%d\n", dp[len-1]);
    }    
    //end
    return 0;
}

bool check(int a, int b)
{
    while(a < b)
        if(buf[a++] != buf[b--])
            return false;
    return true;
}
