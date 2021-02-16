#include<bits/stdc++.h>

using namespace std;


string st;

void append(char a, int cnt)
{
    for (int i = 0; i < cnt; i++)
        st += a;
}


int P[1000][1000];

int main()
{
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) cin >> P[i][j];


    if (C % 2 == 0 && R % 2 == 0)
    {
        int x = 0, y = 1;
        for (int i = 0; i < C; i++)
            for (int j = 0; j < R; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    if (P[x][y] > P[j][i])
                    {
                        x = j;
                        y = i;
                    }
                }

            }
        int mx = 0;
        int my = 0;
        while (x / 2 != mx / 2)
        {
            append('R', C - 1);
            append('D', 1);
            append('L', C - 1);
            append('D', 1);
            mx += 2;
        }
        while (my < y - 1)
        {
            append('D', 1);
            append('R', 1);
            append('U', 1);
            append('R', 1);
            my += 2;
        }
        if (my + 1 == y)
        {
            append('D', 1);
            append('R', 1);
            my += 1;
            mx += 1;
        }
        else if (mx + 1 == x)
        {
            append('R', 1);
            append('D', 1);
            my += 1;
            mx += 1;
        }
        while (my != C - 1)
        {
            append('R', 1);
            append('U', 1);
            append('R', 1);
            append('D', 1);
            my += 2;
        }
        while (mx != R - 1)
        {
            append('D', 1);
            append('L', C - 1);
            append('D', 1);
            append('R', C - 1);
            mx += 2;
        }
        cout << st;
    }

    else if (R % 2 == 1)
    {
        int j = 0;
        for (int i = 0; i < R; i++)
        {
            while (1)
            {
                if (i % 2 == 0)
                {
                    j++;
                    cout << "R";
                }
                else
                {
                    j--;
                    cout << "L";
                }
                if (j == 0 || j == C - 1)
                {
                    if (i != R - 1) cout << "D";
                    break;
                }
            }
        }
    }
    else if (C % 2 == 1)
    {
        int j = 0;
        for (int i = 0; i < C; i++)
        {
            while (1)
            {
                if (i % 2 == 0)
                {
                    j++;
                    cout << "D";
                }
                else
                {
                    j--;
                    cout << "U";
                }
                if (j == 0 || j == R - 1)
                {
                    if (i != C - 1) cout << "R";
                    break;
                }
            }
        }
    }
}