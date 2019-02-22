#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 1e6 + 5;

void add1(char *num, int len)
{
    num[len] += 1;
    for(int i = len; i > 0 && num[i] > '9'; --i)
    {
        num[i] = '0';
        num[i-1] += 1;
    }
}

bool LeftIsGreater(char *num, int len)
{
    int mid = len / 2;
    int i = mid;
    while(num[i] == num[len-i+1])
        --i;
    return num[i] > num[len-i+1];
}

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //init
    int t;
    char num[MAX];
    //input
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", num + 1);
        int len = strlen(num + 1);
        int mid = len / 2;
        if(len & 1)
            ++mid;
        //process
        bool is_palin = true, all9 = true;
        for(int i = 1; i <= mid; ++i)
        {
            if(num[i] != '9')
                all9 = false;
            if(num[i] != num[len-i+1])
            {
                is_palin = false;
                all9 = false;
                break;
            }
        }
        if(all9)
        {
            putchar('1');
            for(int i = 1; i < len; ++i)
                putchar('0');
            putchar('1');
            putchar('\n');
            continue;
        }
        else if(is_palin || !LeftIsGreater(num, len))
            add1(num, mid);
        //output
        for(int i = 1; i <= mid; ++i)
            putchar(num[i]);
        for(int i = (len & 1)? mid-1: mid; i >= 1; --i)
            putchar(num[i]);
        putchar('\n');
    }
    return 0;
}
