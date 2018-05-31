#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <assert.h>
using namespace std;

const int MAX = 50 * 4 + 20;

char mat[200+20][MAX];
char num[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char word[] = "WAKJSD";
char sorted[] = "ADJKSW";
map<char, int> busket;
int h, w;

inline void init();
int dfs_edge(int x, int y);
void dfs_hole(int x, int y);
void init_dfs(int x, int y);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int cnt = 0;
    while(scanf("%d %d", &h, &w) == 2 && h && w)
    {
        init();
        char buf[210];
        for(int i = 1; i <= h; ++i)
        {
            scanf("%s", buf);
            mat[i][1] = '\0';
            for(int j = 0; j < w; ++j)
            {
                int v = isalpha(buf[j])? buf[j]-'a'+10: buf[j]-'0';
                sprintf(mat[i], "%s%s", mat[i], num[v]);
            }
        }
        w *= 4;
        //work
        //step 1
        init_dfs(0, 0);
        //step 2
        for(int i = 1; i <= h; ++i)
            for(int j = 1; j <= w; ++j)
                if(mat[i][j] == '1')
                    ++busket[word[dfs_edge(i, j)]];
        //output
        printf("Case %d: ", ++cnt);
        for(int i = 0; i < sizeof(sorted); ++i)
            for(int j = 0; j < busket[sorted[i]]; ++j)
                printf("%c", sorted[i]);
        printf("\n");
    }
    //end
    return 0;
}

void init()
{
    for(int i = 0; i < sizeof(sorted); ++i)
        busket[sorted[i]] = 0;
    memset(mat, '0', sizeof(mat));
}

void init_dfs(int x, int y)
{
    if(x < 0 || x > h+2 || y < 0 || y > w+2)
        return;
    else if(mat[x][y] != '0' && mat[x][y] != '\0')
        return;
    mat[x][y] = '2';
    for(int i = -1; i <= 1; ++i)
        for(int j = -1; j <= 1; ++j)
            if(i || j)
                init_dfs(x+i, y+j);
}

int dfs_edge(int x, int y)
{
    int hole = 0;
    if(mat[x][y] == '0')
    {
        ++hole;
        dfs_hole(x, y);
    }
    else if(mat[x][y] == '1')
    {
        mat[x][y] = '3';
        for(int i = -1; i <= 1; ++i)
            for(int j = -1; j <= 1; ++j)
                if(i || j)
                    hole += dfs_edge(x+i, y+j);
    }
    return hole;
}

void dfs_hole(int x, int y)
{
    if(mat[x][y] != '0')
        return;
    mat[x][y] = '4';
    for(int i = -1; i <= 1; ++i)
        for(int j = -1; j <= 1; ++j)
            if(i || j)
                dfs_hole(x+i, y+j);
}
