#include <bits/stdc++.h>


using namespace std;


bool dp[2600][2600] = {false};
int dp2[2600];
string st;
int main()
{
	cin >> st;
	int N = st.size();
	st = " " + st;
	for (int i = 1; i <= N; i++)
	{
		dp[i][i] = true;
		if (i != N)
		{
			if (st[i] == st[i + 1]) dp[i][i + 1] = true;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			if (dp[j + 1][i + j - 1] && st[j] == st[i + j])
				dp[j][i + j] = true;
		}
	}
	dp2[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp2[i] = 1e9;
		for (int j = 1; j <=i; j++)
		{
			if (dp[j][i])
			{
				dp2[i] = min(dp2[i], dp2[j - 1] + 1);
			}
		}
	}
	cout << dp2[N] << endl;
	return 0;
}