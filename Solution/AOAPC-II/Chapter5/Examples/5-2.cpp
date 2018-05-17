#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 30;

vector<int> posit[MAX];
int n;

void init();
void find_(int aim, int &pos, int &h);
void clear_above(int pos, int h);
void pile_over(int pos, int h, int p2);
void output();

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    cin >>n;
    init();
    string op1, op2;
    int a, b;
    while(cin >>op1 >>a >>op2 >>b)
    {
        //work
        int p_a, h_a, p_b, h_b;
        find_(a, p_a, h_a);
        find_(b, p_b, h_b);
        if(p_a == p_b)
            continue;
        if(op1 == "move")
            clear_above(p_a, h_a);
        if(op2 == "onto")
            clear_above(p_b, h_b);
        pile_over(p_a, h_a, p_b);
    }
    //output
    output();
    //end
    return 0;
}

void init()
{
    for(int i = 0; i < n; ++i)
        posit[i].push_back(i);
}

void find_(int aim, int &pos, int &h)
{
    for(pos = 0; pos < n; ++pos)
        for(h = 0; h < posit[pos].size(); ++h)
            if(posit[pos][h] == aim)
                return;
}

void clear_above(int pos, int h)
{
    for(int i = h + 1; i < posit[pos].size(); ++i)
    {
        int now = posit[pos][i];
        posit[now].push_back(now);
    }
    posit[pos].resize(h + 1);
}

void pile_over(int pos, int h, int p2)
{
    for(int i = h; i < posit[pos].size(); ++i)
        posit[p2].push_back(posit[pos][i]);
    posit[pos].resize(h);
}

void output()
{
    for(int i = 0; i < n; ++i)
    {
        cout <<i <<":";
        for(int j = 0; j < posit[i].size(); ++j)
            cout <<" " <<posit[i][j];
        cout <<"\n";
    }
 
}
