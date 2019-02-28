#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 505;

int len;
char str[MAX], *num;
bool mark[MAX];
int front[MAX], back[MAX];

inline bool lesst(int al, int ar, int bl, int br)
{
    while(num[al] == '0' && al <= br)
        ++al;
    while(num[bl] == '0' && bl <= br)
        ++bl;
    int lena = ar - al + 1;
    int lenb = br - bl + 1;
    if(lena != lenb)
        return lena < lenb;
    else
    {
        for(int i = 0; i < lena; ++i)
            if(num[al+i] != num[bl+i])
                return num[al+i] < num[bl+i];
    }
    return false;
}

inline void front_dp()
{
    for(int i = 1; i <= len; ++i)
    {
        front[i] = 1;
        for(int j = i; j > 1; --j)
        {
            if(lesst(front[j-1], j-1, j, i))
            {
                front[i] = j;
                break;
            }
        }
    }
}

inline void back_dp()
{
    int end = len;
    while(num[end] == '0')
        back[end--] = len;
    back[front[end]] = len;
    for(int i = front[len]-1; i >= 1; --i)
    {
        back[i] = len;
         for(int j = front[len]-1; j >= i; --j)
             if(lesst(i, j, j+1, back[j+1]))
            {
                back[i] = j;
                break;
            }
    }
}

int main()
{
    // freopen("data.in", "r", stdin);
    scanf("%s", str+1);
    num = str;
    while(num[1] == '0')
        ++num;
    len = strlen(num+1);
    front_dp();
    back_dp();
    for(int i = 1; str+i <= num; ++i)
        putchar('0');
    for(int i = 1; i <= len; i = back[i] + 1)
    {
        for(int j = i; j <= back[i]; ++j)
            putchar(num[j]);
        if(back[i] != len)
            putchar(',');
    }
    putchar('\n');
    return 0;
}
