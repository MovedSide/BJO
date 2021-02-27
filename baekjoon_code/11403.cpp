#include<bits/stdc++.h>

using namespace std;


int g[100][100] = { 0, };
int dp[100][100] = { 0, };
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> g[i][j];
			dp[i][j] = g[i][j];
		}
	}
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int z = 0; z < N; z++)
			{
				if (dp[y][x] == 1 && dp[x][z] == 1)
					dp[y][z] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
