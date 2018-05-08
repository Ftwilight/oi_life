#include <iostream>
#include <cstdio>
using namespace std;

const char dict[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //work
    char t;
    int i = 0;
    while((t = getchar()) != EOF)
    {
        for(i = 0; t != dict[i] && dict[i]; ++i)
            ;
        if(dict[i])
            putchar(dict[i-1]);
        else
            putchar(t);
    }
    return 0;
}
