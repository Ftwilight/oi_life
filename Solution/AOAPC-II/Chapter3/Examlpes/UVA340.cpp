#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1005;

int seq[MAX], bucket_s[10], bucket_g[10];

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //work
    int n, t, cnt = 0;
    while(scanf("%d", &n) && n != 0)
    {
        ++cnt;
        printf("Game %d:\n", cnt);
        //secret code
        memset(bucket_s, 0, sizeof(bucket_s));
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", seq + i);
            ++bucket_s[seq[i]];
        }
        //guess
        while(true)
        {
            int ans_a = 0, ans_b = 0;
            memset(bucket_g, 0, sizeof(bucket_g));
            for(int i = 0; i < n; ++i)
            {
                scanf("%d", &t);
                if(t == seq[i])
                    ++ans_a;
                ++bucket_g[t];
            }
            for(int i = 1; i <= 9; ++i)
                ans_b += min(bucket_s[i], bucket_g[i]);
            ans_b -= ans_a;
            //output
            if(t)
                printf("    (%d,%d)\n", ans_a, ans_b);
            else 
                break;
        }
    }
    return 0;
}
