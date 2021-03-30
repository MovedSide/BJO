#include<bits/stdc++.h>

using namespace std;

string st1, st2;


int dp[1001][1001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> st1 >> st2;
	int i, j;
	for (i = 1; i <= st1.size(); i++)
	{
		for (j = 1; j <= st2.size(); j++)
		{
			dp[i][j] = max({ dp[i - 1][j],dp[i][j - 1], dp[i - 1][j - 1] + (st1[i - 1] == st2[j - 1]) });
		}
	}
	cout << dp[i - 1][j - 1];
	return 0;
}