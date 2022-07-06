#include <bits/stdc++.h>


using namespace std;



int n;
int a[2001];
int dp[2001][2001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	memset(dp, false, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = true;
		if (a[i] == a[i + 1] && i!=n)
			dp[i][i + 1] = true;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j+i <= n; j++)
		{
			if (a[j] == a[i + j] && dp[j + 1][i + j - 1])
			{
				dp[j][i + j] = true;
			}
		}
	}
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{ 
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << "\n";
	}
	return 0;
}