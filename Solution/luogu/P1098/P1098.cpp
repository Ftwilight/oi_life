#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
const int INF = 0x3f3f3f3f;
const char MAX_ASCII = '~';
const char MIN_ASCII = ' ';

int p1, p2, p3;
string aim;
vector<char> result;
char get_char(char i);
bool is_ok(char last, char next);

int main()
{
    //input
    cin >>p1 >>p2 >>p3 >>aim;
    //work
    for(int i=0; i<aim.size(); ++i)
    {
        char now = aim[i];
        char next = (i==aim.size()-1)? MIN_ASCII: aim[i+1];
        char last = (i==0)? MAX_ASCII: aim[i-1];
        if(now=='-' && is_ok(last, next))
        {
            if(p3 == 1)
                for(char i=last+1; i<next; ++i)
                    for(int cnt=0; cnt<p2; ++cnt)
                        result.push_back(get_char(i));
            else
                for(char i=next-1; i>last; --i)
                    for(int cnt=0; cnt<p2; ++cnt)
                        result.push_back(get_char(i));
        }
        else
            result.push_back(now);
    }
    //output
    for(int i=0; i<result.size(); ++i)
        cout <<result[i];
    return 0;
}

char get_char(char i)
{
    if(p1 == 1)
        return tolower(i);
    else if(p1 == 2)
        return toupper(i);
    else
        return '*';
}

bool is_ok(char last, char next)
{
    if(last < next)
    {
        if(isdigit(last) && isdigit(next))
            goto ok;
        if(islower(last) && islower(next))
            goto ok;
    }
    return false;
    ok:return true;
}
