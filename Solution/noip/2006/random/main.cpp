#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 1005;

int box[MAX];

int main()
{
    //file
    //freopen("random.in", "r", stdin);
    //freopen("random.out", "w", stdout);
    //input
    int n, t, cnt = 0;
    cin >>n;
    for(int i = 0; i < n; ++i)
    {
        cin >>t;
        ++box[t];
        if(box[t] == 1)
            ++cnt;
    }
    //output
    cout <<cnt <<"\n";
    for(int i = 1; i <= 1000; ++i)
        if(box[i])
            cout <<i <<" ";
    return 0;
}
