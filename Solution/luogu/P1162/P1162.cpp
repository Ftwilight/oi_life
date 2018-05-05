#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 31;
int n;
int mat[MAX][MAX];

int work();
int main()
{
    //input
    cin >>n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >>mat[i][j];
    //work
    work();
    //output
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
            cout <<mat[i][j] <<" ";
        cout <<"\n";
    }
    return 0;
}

int work()
{
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            int flag = 0;
            //up
            for(int t=i-1; t>=0; --t)
                if(mat[t][j] == 1)
                {
                    ++flag;
                    break;
                }
            //down
            for(int t=i+1; t<n; ++t)
                if(mat[t][j] == 1)
                {
                    ++flag;
                    break;
                }
            //left
            for(int t=j-1; t>=0; --t)
                if(mat[i][t] == 1)
                {
                    ++flag;
                    break;
                }
            //right
            for(int t=j+1; t<n; ++t)
                if(mat[i][t] == 1)
                {
                    ++flag;
                    break;
                }
            //judge
            if(flag == 4 && mat[i][j] == 0)
                mat[i][j] = 2;
        }
}
