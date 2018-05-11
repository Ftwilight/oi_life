#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 105;
const int limit = 7;
char ans[MAX], seq[MAX];

int guess();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    while(scanf("%d", &n) && n != -1)
    {
        scanf("%s%s", ans, seq);
        //work
        int res = guess();
        //output
        printf("Round %d\n", n);
        if(res == 0)
            printf("You lose.");
        else if(res == 1)
            printf("You win.");
        else
            printf("You chickened out.");
        printf("\n");
    }
    //end
    return 0;
}

int guess()
{
    int ans_len = strlen(ans);
    int seq_len = strlen(seq);
    
    int chance = limit;
    int left = ans_len;
    for(int i = 0; i < seq_len; ++i)
    {
        bool flag = true;
        for(int j = 0; j < ans_len; ++j)
            if(ans[j] == seq[i])
            {
                flag = false;
                ans[j] = ' ';
                --left;
            }

        if(flag)
            --chance;
        if(!chance)
            return 0;
        else if(!left)
            return 1;
    }
    return 2;
}

