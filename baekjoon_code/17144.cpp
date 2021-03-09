#include<bits/stdc++.h>

using namespace std;


int lo[50][50];
int new_lo[50][50];
int x_1 = 0;
int x_2 = 0;
int r, c, t;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool is_valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= r || y >= c) return false;
    if ((x == x_1 && y == 0) || (x == x_2 && y == 0)) return false;
    return true;
}

void set_dust(int x, int y)
{
    int cnt = 0;
    int dust = lo[x][y] / 5;
    int el = lo[x][y];
    for (int i = 0; i < 4; i++)
    {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (is_valid(mx, my))
        {
            new_lo[mx][my] += dust;
            el -= dust;
        }
    }
    new_lo[x][y] += el;
}
void set_field()
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) new_lo[i][j] = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (lo[i][j] > 0)
                set_dust(i, j);
        }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) lo[i][j] = new_lo[i][j];
}
void move_dust()
{
    for (int i = x_1 - 1; i > 0; i--)
    {
        lo[i][0] = lo[i - 1][0];
    }
    for (int i = 0; i < c-1; i++)
    {
        lo[0][i] = lo[0][i+1];
    }
    for (int i = 0; i < x_1; i++)
    {
        lo[i][c-1] = lo[i + 1][c-1];
    }
    for (int i = c-1; i > 0; i--)
    {
        lo[x_1][i] = lo[x_1][i-1];
    }

    for (int i = x_2 + 1; i < r-1; i++)
    {
        lo[i][0] = lo[i + 1][0];
    }
    for (int i = 0; i < c - 1; i++)
    {
        lo[r-1][i] = lo[r-1][i + 1];
    }
    for (int i = r-1; i > x_2; i--)
    {
        lo[i][c - 1] = lo[i - 1][c - 1];
    }
    for (int i = c - 1; i > 0; i--)
    {
        lo[x_2][i] = lo[x_2][i - 1];
    }
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> lo[i][j];
            if (lo[i][j] == -1)
            {
                if (x_1) x_2 = i;
                else x_1 = i;
            }
        }
    }
    while (t--)
    {
        set_field();
        move_dust();
    }
    int sum = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) sum += lo[i][j];
    cout << sum;
    return 0;
}