#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int lamp[50][50];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            scanf("%1d", &lamp[i][j]);
    }
    int K;
    cin >> K;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        int same = 1;
        for (int j = 0; j < M; j++)
        {
            if (lamp[i][j] == 0) cnt++;
        }
        if (cnt > K || cnt % 2 != K % 2) continue;

        for (int x = 0; x < N; x++)
        {
            if (x == i) continue;
            bool is_same = true;
            for (int y = 0; y < M; y++)
            {
                if (lamp[i][y] != lamp[x][y])
                {
                    is_same = false;
                    break;
                }
            }
            if (is_same == true) same++;
        }
        if (max < same) max = same;
    }


    cout << max;





    return 0;
}