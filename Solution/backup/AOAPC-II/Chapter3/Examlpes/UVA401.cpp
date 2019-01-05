#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const char* msg[] = {" -- is not a palindrome.", " -- is a regular palindrome.", " -- is a mirrored string.", " -- is a mirrored palindrome."};
const char dict[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char res(char ori)
{
    if(isdigit(ori))
        return dict[ori - '0' + 25];
    else
        return dict[ori - 'A'];
}

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //work
    char t[100];
    while(scanf("%s", t) == 1)
    {
        int is_p = 1, is_m = 2;
        int size = strlen(t);
        for(int i = 0; i < (size + 1)/2; ++i)
        {
            if(t[i] != t[size - i - 1])
                is_p = 0;
            if(t[i] != res(t[size - i - 1]))
                is_m = 0;
        }
        printf("%s%s\n\n", t, msg[is_p + is_m]);
    }
    return 0;
}
