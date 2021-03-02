#include<bits/stdc++.h>

using namespace std;


int dp[50001];

int main()
{
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 987654321;
		for (int j = 0; j <= sqrt(i); j++)
		{
			int num = j * j;
			dp[i] = min(dp[i], dp[i - num] + 1);
		}
	}
	cout << dp[n];
	return 0;
}