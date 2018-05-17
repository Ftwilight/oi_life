#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 105;
const int INF = 0x3f3f3f3f;

string name[MAX];

inline void line();
void output(const string &file, int len);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    while(cin >>n)
    {
        int size = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >>name[i];
            size = max(size, static_cast<int>(name[i].length()));
        }
        //work
        int c = 62 / (size + 2);
        int l = (n / c) + ((n % c)? 1: 0);
        sort(name + 1, name + n + 1);
        //output
        line();
        for(int i = 1; i <= l; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(i + j * l <= n)
                    output(name[i + j * l], size + ((j == c-1)? 0: 2));
            }
            cout <<"\n";
        }
    }
    //end
    return 0;
}

inline void line()
{
    for(int i = 0; i < 60; ++i)
        cout <<"-";
    cout <<"\n";
}

void output(const string &name, int len)
{
    cout <<name;
    for(int i = 0; i < len - name.length(); ++i)
        cout <<" ";
}
