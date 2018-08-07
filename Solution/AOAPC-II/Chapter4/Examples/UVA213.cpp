#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 8;

char code[MAX][1 << MAX];

inline char readchar();
int readint(int l);
bool readcode();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    while(readcode())
    {
        //work
        while(true)
        {
            int len = readint(3);
            if(!len)
                break;
            while(true)
            {
                int t = readint(len);
                if(t == (1 << len) - 1)
                    break;
                else
                    printf("%c", code[len][t]);
            }
        }
        printf("\n");
    }
    //end
    return 0;
}

inline char readchar()
{
    char c = getchar();
    while(c == '\n' || c == '\r')
        c = getchar();
    return c;
}

bool readcode()
{
    code[1][0] = readchar();
    for(int len = 2; len < MAX; ++len)
        for(int i = 0; i < (1<<len)-1; ++i)
        {
            char t = getchar();
            if(t == EOF)
                return false;
            else if(t == '\n' || t =='\r')
                return true;
            else
                code[len][i] = t;
        }
    return true;
}

int readint(int len)
{
    int power = len;
    int res = 0;
    for(int i = 0; i < len; ++i)
        res += (readchar() - '0') * pow(2, --power);
    return res;
}
