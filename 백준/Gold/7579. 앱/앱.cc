#include <bits/stdc++.h>


using namespace std;
int N, M;
int m[101];
int c[101];
int dp[101][10001];

int main()
{

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> m[i];
	int x = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
		x += c[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (j >= c[i])
				dp[i][j] = dp[i - 1][j - c[i]] + m[i];
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i <= x; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i;
			exit(0);
		}
	}
	return 0;
}