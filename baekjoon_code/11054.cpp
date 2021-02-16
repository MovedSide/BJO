#include<bits/stdc++.h>
using namespace std;

long long dp[2][1000];
int a[1000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j]) dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j]) dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
    }
    long long len = 0;
    for (int i = 0; i < n; i++)
    {
        len = max(len, dp[0][i] + dp[1][i] - 1);
    }
    cout << len;
    return 0;
}