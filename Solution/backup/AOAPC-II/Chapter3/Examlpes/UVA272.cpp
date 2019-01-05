#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input and work
    bool flag = false;
    char t;
    while(scanf("%c", &t) != EOF)
    {
        if(t == '\"')
        {
            if(flag)
                printf("\'\'");
            else
                printf("``");
            flag = !flag;
        }
        else
            printf("%c", t);
    }
    return 0;
}
