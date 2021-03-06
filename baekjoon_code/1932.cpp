#include<bits/stdc++.h>

using namespace std;

vector<int> num[500];
int dp[500][500] = { 0, };
int n;


int func(int x,int y)
{
	if (x == n - 1) return num[x][y];
	if (dp[x][y])
	{
		return dp[x][y];
	}
	int left = func(x + 1, y);
	int right = func(x + 1, y+1);
	dp[x][y] = num[x][y] + max(left, right);
	return dp[x][y];
}





int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int inp;
			cin >> inp;
			num[i].push_back(inp);
		}
	}
	func(0, 0);
	cout << dp[0][0];
	return 0;
}