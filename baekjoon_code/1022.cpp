#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int print_num(int x, int y, int p)
{
    int t = max(abs(x), abs(y));
    int start = pow(t * 2 + 1, 2);
    int i;
    int j;
    i = j = t;
    int sw = 1;
    int num = start;
    while (true)
    {
        if (i == x && j == y) break;
        if (sw == 1) j--;
        else if (sw == 2) i--;
        else if (sw == 3) j++;
        else if (sw == 4) i++;
        num--;
        if (abs(i) == abs(j))
        {
            if (j == (-1) * t && i == (1) * t) sw = 2;
            if (j == (-1) * t && i == (-1) * t) sw = 3;
            if (j == (1) * t && i == (-1) * t) sw = 4;
        }

    }

    return num;
}
int set_num(int x1, int y1, int x2, int y2, int bo[][5])
{
    int a = max(abs(x1), abs(y1));
    int b = max(abs(x2), abs(y2));
    int k = max(a, b);
    int q = pow(k * 2 + 1, 2);
    int cnt = 0;
    while (q)
    {
        q /= 10;
        cnt++;
    }
    int x, y;
    x = y = 0;
    int m = 0;
    for (int i = x1; i <= x2; i++)
    {
        y = 0;
        for (int j = y1; j <= y2; j++)
        {
            bo[x][y] = print_num(i, j, cnt);
            m = max(m, bo[x][y]);
            y++;
        }
        x++;
    }
    return m;
}



int main()
{
    int r1, c1, r2, c2;
    int b[50][5], max;
    cin >> r1 >> c1 >> r2 >> c2;

    max = set_num(r1, c1, r2, c2, b);
    int cnt = 0;
    while (max)
    {
        max /= 10;
        cnt++;
    }
    for (int i = 0; i <= r2 - r1; i++)
    {
        for (int j = 0; j <= c2 - c1; j++)
        {
            printf("%*d", cnt, b[i][j]);
            printf(" ");
        }
        cout << endl;
    }
    return 0;
}