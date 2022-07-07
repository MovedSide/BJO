#include <bits/stdc++.h>


using namespace std;



int cost[1000][3];
int dp[1000][3];


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[i][j];
		}
	}
	int an = 1000 * 1000 + 1;
	for (int t = 0; t < 3; t++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (t == i) dp[0][i] = cost[0][i];
			else
			{
				dp[0][i] = 1001;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (t == i) continue;
			an = min(an, dp[n - 1][i]);
		}
	}
	cout << an;
	return 0;
}