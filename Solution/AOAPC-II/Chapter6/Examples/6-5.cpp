#include <cstdio>
#include <cstring>

const int MAX = 100010;

char s[MAX];
int next[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(scanf("%s", s+1) == 1)
    {
        //work
        int now = 0, last = 0;
        int len = strlen(s+1);
        next[0] = 0;
        for(int i = 1; i <= len; ++i)
        {
            if(s[i] == '[')
                now = 0;
            else if(s[i] == ']')
                now = last;
            else
            {
                next[i] = next[now];
                next[now] = i;
                if(now == last)
                    last = i;
                now = i;
            }
        }
        for(int i = next[0]; i; i = next[i])
            printf("%c", s[i]);
        printf("\n");
        
    }
}
