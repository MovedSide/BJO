#include<bits/stdc++.h>

using namespace std;




pair<int, int> dp[41];



int main()
{
	int T;
	cin >> T;
	int max_num = -1;
	while (T--)
	{
		int N;
		cin >> N;
		if (max_num < N)
		{
			for (int i = max_num + 1; i <= N; i++)
			{
				if (i == 0)
				{
					dp[i].first = 1;
				}
				else if (i == 1)
				{
					dp[i].second = 1;
				}
				else
				{
					dp[i].first = dp[i - 1].first + dp[i - 2].first;
					dp[i].second = dp[i - 1].second + dp[i - 2].second;

				}
			}
			max_num = N;
		}
		cout << dp[N].first << " " << dp[N].second << endl;
	}

	return 0;
}