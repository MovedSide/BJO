#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

char** b;
int N, M, t;
int dp[52][52];
int visit[52][52];


bool is_visit(int x, int y)
{
    if (visit[x][y] == 1)
        return true;
    return false;
}
bool is_safe(int x, int y)
{
    if (y >= M) return false;
    if (x >= N) return false;
    if (y < 0) return false;
    if (x < 0) return false;
    if (b[x][y] == 'H') return false;
    return true;
}
int move_coin(int x, int y)
{
    if (!is_safe(x, y))
    {
        return 0;
    }
    if (is_visit(x, y))
    {
        cout << "-1" << endl;
        exit(0);
    }
    if (dp[x][y]) return dp[x][y];
    visit[x][y] = 1;

    int el = b[x][y] - '0';

    dp[x][y] = max(dp[x][y], move_coin(x + el, y) + 1);


    dp[x][y] = max(dp[x][y], move_coin(x, y + el) + 1);



    dp[x][y] = max(dp[x][y], move_coin(x - el, y) + 1);



    dp[x][y] = max(dp[x][y], move_coin(x, y - el) + 1);

    visit[x][y] = 0;
    return dp[x][y];
}

int main()
{
    cin >> N >> M;
    b = new char* [N];
    t = 0;
    for (int i = 0; i < N; i++)
        b[i] = new char[M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> b[i][j];
        }
    int el = move_coin(0, 0);
    cout << el;
    return 0;
}