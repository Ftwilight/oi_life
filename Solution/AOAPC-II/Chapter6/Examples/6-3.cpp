#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100005;
char sen[MAX];
int last, now, next[MAX];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(scanf("%s", sen + 1) == 1)
    {
        int len = strlen(sen + 1);
        now = last = 0;
        next[0] = 0;
        for(int i = 1; i <= len; ++i)
        {
            char ch = sen[i];
            if(ch == '[')
                now = 0;
            else if(ch == ']')
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
        for(int i = next[0]; i != 0; i = next[i])
            printf("%c", sen[i]);
        printf("\n");
    }
    //end
    return 0;
}
