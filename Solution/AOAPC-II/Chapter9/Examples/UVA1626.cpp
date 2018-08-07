#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 105;

string q, buf;
int d[MAX][MAX], l;

void output(int i, int j);
inline void clear();
inline bool match(int a, int b);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //input
    int all;
    cin >>all;
    clear();
    clear();
    while(all--)
    {
        getline(cin, q);
        //work
        l = q.length();
        for(int i = 0; i < l; ++i)
            d[i][i] = 1;
        for(int i = l-2; i >= 0; --i)
            for(int j = i+1; j < l; ++j)
            {
                d[i][j] = l;
                if(match(i, j))
                    d[i][j] = min(d[i][j], d[i+1][j-1]);
                for(int k = i; k < j; ++k)
                    d[i][j] = min(d[i][j], d[i][k]+d[k+1][j]);
            }
        //output
        output(0, l-1);
        cout <<"\n";
        if(all)
            cout <<"\n";
        clear();
    }
    //end
    return 0;
}

inline bool match(int a, int b)
{
    return (q[a]=='[' && q[b]==']') || (q[a]=='(' && q[b]==')');
}

void output(int i, int j)
{
    if(i > j)
        return;
    else if(i == j)
    {
        if(q[i] == '(' || q[i] == ')')
            cout <<"()";
        else
            cout <<"[]";
    }
    else
    {
        int ans = d[i][j];
        if(match(i, j) && ans == d[i+1][j-1])
        {
            cout <<q[i];
            output(i+1, j-1);
            cout <<q[j];
        }
        else
        {
            for(int k = i; k < j; ++k)
                if(ans == d[i][k]+d[k+1][j])
                {
                    output(i, k);
                    output(k+1, j);
                    return;
                }
        }
    }
}

inline void clear()
{
    getline(cin, buf);
}
