#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 15;

class Mat
{
private:
    char getc()
    {
        char c = getchar();
        while(c != '@' && c != '-')
            c = getchar();
        return c;
    }


public:
    int n;
    char mat[MAX][MAX];
    Mat(int n_ = 0):n(n_)
    {
        memset(mat, 0, sizeof(0));
    }
    //~Mat()
    //{
    //    delete mat;
    //}
    void operator=(Mat other)
    {
        n = other.n;
        memcpy(mat, other.mat, sizeof(mat));
        // return this;
    }
    bool operator==(Mat other)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] != other.mat[i][j])
                    return false;
        return true;
    }
    Mat rotate()
    {
        Mat ans(n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ans.mat[i][j] = mat[n-j-1][i];
        return ans;
    }
    Mat reflect()
    {
        Mat ans(n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ans.mat[i][j] = mat[i][n-j-1];
        return ans;
    }
    void input()
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                mat[i][j] = getc();
    }
};

Mat rotate(int cnt, Mat m)
{
    while(cnt--)
        m = m.rotate();
    return m;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    Mat ori(n), aim(n);
    ori.input();
    aim.input();
    Mat t;

    if(rotate(1, ori) == aim)
        putchar('1');
    else if(rotate(2, ori) == aim)
        putchar('2');
    else if(rotate(3, ori) == aim)
        putchar('3');
    else if(ori.reflect() == aim)
        putchar('4');
    else if(rotate(1, ori.reflect()) == aim || rotate(2, ori.reflect()) == aim || rotate(3, ori.reflect()) == aim)
        putchar('5');
    else if(ori == aim)
        putchar('6');
    else
        putchar('7');
    return 0;
}
