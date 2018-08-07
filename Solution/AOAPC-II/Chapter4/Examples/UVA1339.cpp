#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 105;
int cnt_a[30], cnt_b[30];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //work
    char a[MAX], b[MAX];
    while(scanf("%s%s", a, b) == 2)
    {
        memset(cnt_a, 0, sizeof(cnt_a));
        memset(cnt_b, 0, sizeof(cnt_b));
        int len = strlen(a);
        for(int i = 0; i < len; ++i)
        {
            ++cnt_a[a[i] - 'A'];
            ++cnt_b[b[i] - 'A'];
        }
        sort(cnt_a, cnt_a + 26);
        sort(cnt_b, cnt_b + 26);

        bool flag = true;
        for(int i = 0; i < 26; ++i)
            if(cnt_a[i] != cnt_b[i])
                flag = false;

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    //end
    return 0;
}
