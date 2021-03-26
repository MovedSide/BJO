#include<bits/stdc++.h>

using namespace std;

int N, K;

pair<int, int> gd[101];
int dp[101][100000];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> gd[i].first >> gd[i].second;
	}
	for(int i=1;i<=N;i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j < gd[i].first)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - gd[i].first] + gd[i].second);
			}
		}
	}
	cout << dp[N][K];
	return 0;
}