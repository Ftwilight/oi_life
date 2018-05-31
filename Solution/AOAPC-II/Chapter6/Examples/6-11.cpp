#include <cstdio>
#include <cstring>

const int SIZE = 32;

bool g[SIZE][SIZE];
char buf[2 << 12];
int ans;

void draw(const char *s, int &now, int x, int y, int wide);

int main()
{
    //file
    //freopen("data.in", "r", stdin);
    //input
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        //work
        ans = 0;
        memset(g, 0, sizeof(g));
        for(int i = 0; i < 2; ++i)
        {
            scanf("%s", buf);
            int p = 0;
            draw(buf, p, 0, 0, SIZE);
        }
        //output
        printf("There are %d black pixels.\n", ans);
    }
    //end
    return 0;
}

void draw(const char *s, int &now, int x, int y, int wide)
{
    char ch = s[now++];
    if(ch == 'p')
    {
        draw(s, now, x, y+wide/2, wide/2);
        draw(s, now, x, y, wide/2);
        draw(s, now, x+wide/2, y, wide/2);
        draw(s, now, x+wide/2, y+wide/2, wide/2);
    }
    else if(ch == 'f')
    {
        for(int i = x; i < x+wide; ++i)
            for(int j = y; j < y+wide; ++j)
                if(!g[i][j])
                {
                    g[i][j] = true;
                    ++ans;
                }
    }
}
