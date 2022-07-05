#include <bits/stdc++.h>


using namespace std;




int dp[1000001];
int bf[1000000];

int main()
{
	int n;
	cin >> n;
	dp[1] = 0;
	bf[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		bf[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i/2]+1)
		{
			dp[i] = dp[i / 2]+1;
			bf[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
		{
			dp[i] = dp[i / 3]+1;
			bf[i] = i / 3;
		}
	}
	cout << dp[n] << endl;
	int x = n;
	cout << x << " ";
	while (x!=1)
	{
		cout << bf[x] << " ";
		x = bf[x];
	}
	return 0;
}